#pragma once





#include <iostream>
#include <conio.h>
#include <map>
#include <functional>
#include <mutex>
#include <any>

#include "klass_instance.h"
#include "exceptions.h"
#include "sqlite3.h"
#include "string_utilities.h"


struct db_helper_context {
    std::shared_ptr<klass_definition> mapper;
    std::vector<std::any> results;
};

class db_helper {
public:
    db_helper() {}
    ~db_helper() {}

    void open(const std::string szPath = ":memory:")
    {
        std::scoped_lock lock(mux);
        if (m_db != nullptr) {
            // If db is already active, do nothing
            return;
        }
        int rc = sqlite3_open(szPath.c_str(), &m_db);
        if (rc) {
            throw ProgramException("sql error: " + std::string(sqlite3_errmsg(m_db)), location());
        }
    }


    std::vector<std::any> get(std::string sql, std::shared_ptr<klass_definition> rowmapper = nullptr)
    {
        std::scoped_lock lock(mux);
        check_db();

        if (rowmapper == nullptr) {
            std::shared_ptr<activation_record> ar = std::make_shared<activation_record>();
            ar->environment = std::make_shared<scope<std::any>>();
            rowmapper = std::make_shared<klass_definition>("query_row", ar);
        }

        db_helper_context context;
        context.mapper = rowmapper;
        char* zErrMsg = 0;
        int rc = sqlite3_exec(m_db, sql.c_str(), callback, static_cast<void*>(&context), &zErrMsg);

        if (rc != SQLITE_OK) {
            std::string  szErr = zErrMsg;
            sqlite3_free(zErrMsg);
            throw ProgramException("sql error: " + szErr, location());
        }
        else {
            return context.results;
        }
    };

    static int callback(void* data, int argc, char** argv, char** azColName)
    {

        db_helper_context* context = static_cast<db_helper_context*>(data);
        klass_instance row = context->mapper->create();
        std::string szColumn;
        for (unsigned int i = 0; i < (unsigned int)argc; i++) {
            szColumn = lower(azColName[i]);
            std::any val = argv[i] ? std::string(reinterpret_cast<const char *>(argv[i])) : nullptr;
            row.Define(szColumn, val, location(), true);
        }
        context->results.push_back(row);
        return 0;
    }


    std::vector<std::any> run_prepared(
        const std::string& sql,                     // sql string to execute
        std::vector<std::any> args,                 // arguments to provide as parameters
        std::shared_ptr<klass_definition> mapper,   // prototype of resulting row objects
        bool include_unexpected,                    // whether or not to include in resulting object columns that do not have a corresponding value in the mapper
        int numBinds = 1)                           // number of times to bind and execute the query
    {
        std::scoped_lock lock(mux);
        check_db();
        std::vector<std::any> results;

        sqlite3_stmt* stmt = nullptr;
        try {
            int rc = 0;
            rc = sqlite3_prepare_v2(m_db, sql.c_str(), -1, &stmt, 0);
            if (rc != SQLITE_OK) {
                throw ProgramException("sql error: 1" + std::string(sqlite3_errmsg(m_db)), location());
            }

            for (int bindIndex = 0; bindIndex < numBinds; bindIndex++) {
                unsigned int bind_parameter_count = sqlite3_bind_parameter_count(stmt);
                if (bind_parameter_count != args.size()) {
                    throw ProgramException("sql error: expected " + std::to_string(bind_parameter_count) + " binds but got " + std::to_string(args.size()), location());
                }

                for (unsigned int i = 0; i < bind_parameter_count; i++) {

                    //  Bind-parameter indexing is 1-based.
                    if (args.at(i).type() == typeid(int)) {
                        rc = sqlite3_bind_int(stmt, i + 1, std::any_cast<int>(args.at(i)));
                    }
                    else if (args.at(i).type() == typeid(double)) {
                        rc = sqlite3_bind_double(stmt, i + 1, std::any_cast<double>(args.at(i)));
                    }
                    else if (args.at(i).type() == typeid(nullptr)) {
                        rc = sqlite3_bind_null(stmt, i + 1);
                    }
                    else if (args.at(i).type() == typeid(std::string)) {
                        std::string bindValue = std::any_cast<std::string>(args.at(i));
                        rc = sqlite3_bind_text(stmt, i + 1, bindValue.c_str(), strlen(bindValue.c_str()), nullptr);
                    }
                    else {
                        throw ProgramException("sql error: unsupported parameter type; object type was: " + std::string(args.at(i).type().name()), location());
                    }
                    if (rc != SQLITE_OK) {
                        throw ProgramException("sql error: 2" + std::string(sqlite3_errmsg(m_db)), location());
                    }
                }

                //  Read results
                rc = sqlite3_step(stmt);
                while (rc == SQLITE_ROW) { // While query has result rows.
                    klass_instance row = mapper->create();
                    for (int colIndex = 0; colIndex < sqlite3_column_count(stmt); colIndex++) {
                        std::string szColumnName = lower(sqlite3_column_name(stmt, colIndex));
                        int columnType = sqlite3_column_type(stmt, colIndex); // SQLITE_INTEGER, SQLITE_FLOAT, SQLITE_TEXT, SQLITE_BLOB OR SQLITE_NULL
                        if (include_unexpected) {
                            if (columnType == SQLITE_INTEGER) {
                                row.Define(szColumnName, sqlite3_column_int(stmt, colIndex), location(), true);
                            }
                            else if (columnType == SQLITE_FLOAT) {
                                row.Define(szColumnName, sqlite3_column_double(stmt, colIndex), location(), true);
                            }
                            else if (columnType == SQLITE_TEXT) {
                                std::string value = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, colIndex)));
                                row.Define(szColumnName, value , location(), true);
                            }
                            else if (columnType == SQLITE_NULL) {
                                row.Define(szColumnName, nullptr, location(), true);
                            }
                            else {
                                throw ProgramException("sql error: unsupported column return type of column " + szColumnName, location());
                            }
                        }
                        else {
                            if (row.Exists(szColumnName)) {
                                if (columnType == SQLITE_INTEGER) {
                                    row.Assign(szColumnName, sqlite3_column_int(stmt, colIndex), location());
                                }
                                else if (columnType == SQLITE_FLOAT) {
                                    row.Assign(szColumnName, sqlite3_column_double(stmt, colIndex), location());
                                }
                                else if (columnType == SQLITE_TEXT) {
                                    std::string value = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, colIndex)));
                                    row.Assign(szColumnName, value, location());
                                }
                                else if (columnType == SQLITE_NULL) {
                                    row.Assign(szColumnName, nullptr, location());
                                }
                                else {
                                    throw ProgramException("sql error: unsupported column return type of column " + szColumnName, location());
                                }
                            }
                            else {
                                throw ProgramException("sql error: unable to map column '" + szColumnName + "' to value", location());
                            }
                        }
                    }

                    results.push_back(row);
                    rc = sqlite3_step(stmt);
                }
                if (rc != SQLITE_DONE) {
                    throw ProgramException("sql error: 3" + std::string(sqlite3_errmsg(m_db)), location());
                }
                //  Reset the statement after each bind.

                rc = sqlite3_reset(stmt);
                if (rc != SQLITE_OK) {
                    throw ProgramException("sql error: 4" + std::string(sqlite3_errmsg(m_db)), location());
                }
            }

            rc = sqlite3_finalize(stmt);  //  Finalize the prepared statement.
            if (rc != SQLITE_OK) {
                throw ProgramException("sql error: 6" + std::string(sqlite3_errmsg(m_db)), location());
            }
            return results;
        }
        catch (ProgramException re) {
            sqlite3_finalize(stmt);
            throw re;
        }
    }

    long long query_count() const { return m_queryCount; }

private:

    void check_db()
    {
        if (m_db == nullptr) {
            throw ProgramException("db was null", location(), Severity().CRITICAL());
        }
        m_queryCount++;
    }

    sqlite3* m_db{ nullptr };
    std::mutex mux;
    std::map<std::string, std::string> m_mapper;
    long long m_queryCount{ 0 };
};
