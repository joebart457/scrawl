#pragma once

#include <string>
#include <sstream>
#include <any>
#include <vector>

#include "location.h"

class Severity {
public:
	static std::string LOW() { return "LOW"; }
	static std::string MEDIUM() { return "MEDIUM"; }
	static std::string HIGH() { return "HIGH"; }
	static std::string CRITICAL() { return "CRITICAL"; }
	static std::string FATAL() { return "FATAL"; }
};

struct err_trace {
	std::string szMsg{ "" };
	location loc;
};

class ProgramException {
public:
	ProgramException(const std::string& szMsg, const location& loc, const std::string& szSeverity = Severity().MEDIUM())
		:ProgramException("ProgramException", szMsg, loc, szSeverity){}
	ProgramException(const std::string& szType, const std::string& szMsg, const location& loc, const std::string& szSeverity = Severity().MEDIUM())
		:m_szType{ szType }, m_szMsg{ szMsg }, m_loc{ loc }, m_szSeverity{ szSeverity }{}
	~ProgramException(){}

	std::string severity() { return m_szSeverity; }

	std::string what()
	{
		std::ostringstream oss;
		oss << "{" << m_szSeverity << "}[" << m_szType << "] " << m_szMsg;
		return oss.str();
	}

	virtual std::string fullTrace()
	{
		std::ostringstream oss;
		oss << "[" << m_loc.y() << "][" << m_loc.x() << "] " << m_szType << ": " << m_szMsg << "\n";
		for (auto trace : m_trace) {
			oss << "\tat [" << trace.loc.y() << "][" << trace.loc.x() << "] " << trace.szMsg << "\n";
		}
		return oss.str();
	}

	virtual void addStackTrace(const std::string& szMsg, const location& loc)
	{
		err_trace err;
		err.szMsg = szMsg;
		err.loc = loc;
		m_trace.push_back(err);
	}

protected:
	std::string m_szType;
	std::string m_szMsg;
	std::string m_szSeverity;
	location m_loc;
	std::vector<err_trace> m_trace;
};



class ParsingException :
	public ProgramException {
public:
	ParsingException(const std::string& szMsg, const location& loc, const std::string& szSeverity = Severity().FATAL())
		:ProgramException("ParsingException", szMsg, loc, szSeverity) {}
	~ParsingException(){}
};


class BreakException :
	public ProgramException {
public:
	BreakException(const location& loc)
		:ProgramException("BreakException", "break", loc, Severity().LOW()){}
	~BreakException(){}
};


class ReturnException :
	public ProgramException {
public:
	ReturnException(std::any val, const location& loc)
		:ProgramException("ReturnException", "", loc, Severity().LOW()), m_value{ val }{}
	~ReturnException() {}

	std::any value() { return m_value; }

protected:
	std::any m_value;
};

class PanicException :
	public ProgramException {
public:
	PanicException(std::any val, const location& loc)
		:ProgramException("PanicException", "", loc, Severity().LOW()), m_value{ val }{}
	~PanicException() {}

	std::any value() { return m_value; }

protected:
	std::any m_value;
};