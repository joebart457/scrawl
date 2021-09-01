#pragma once


#ifndef __INCLUDE__PRELIM__UNIVERSAL_FILE_HANDLE_H
#define __INCLUDE__PRELIM__UNIVERSAL_FILE_HANDLE_H

#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include "exceptions.h"

class FileHandle
{
public:
	FileHandle();
	~FileHandle();
	void copyFile(const std::string& source, const std::string& dest);

	uintmax_t removeAll(const std::string& source);
	std::vector<std::string> readFile(const std::string& szFilepath);
	std::string readFileAsString(const std::string& filepath);
	void writeToFile(const std::string& filepath, std::vector<std::string> data, bool overwriteContents = true);
	void writeLine(const std::string& filepath, std::string data, bool overwriteContents = true);
	std::string readLine(const std::string& filepath, unsigned int lineNumber);
	unsigned int countLines(const std::string& filepath);

	static std::string current_path()
	{
		return std::filesystem::current_path().string();
	}

	static std::string parent_path(const std::string& szFilePath)
	{
		std::filesystem::path fp(szFilePath);
		return fp.parent_path().string();
	}

	static void rename(const std::string& szSource, const std::string& szRename)
	{
		std::filesystem::rename(szSource, szRename);
	}

	static uintmax_t file_size(const std::string& szFilePath)
	{
		return std::filesystem::file_size(szFilePath);
	}

	static bool exists(const std::string& szFilePath)
	{
		return std::filesystem::exists(szFilePath);
	}
};


FileHandle::FileHandle()
{
}


FileHandle::~FileHandle()
{
}

void FileHandle::copyFile(const std::string& source, const std::string& dest) {
	const auto copyOptions = std::filesystem::copy_options::update_existing
		| std::filesystem::copy_options::recursive;
	std::filesystem::copy(source, dest, copyOptions);
}

uintmax_t FileHandle::removeAll(const std::string& source) {
	return std::filesystem::remove_all(source);
}


std::vector<std::string> FileHandle::readFile(const std::string& filepath) {
	std::vector<std::string> fileData;
	std::ifstream f(filepath);
	if (f.is_open()) {
		std::string line;
		while (std::getline(f, line)) {
			fileData.push_back(line);
		}
		f.close();
		return fileData;
	}
	else {
		throw PanicException(IOException("unable to perform io operation on file '" + filepath + "'; file not found or unable to open", location()), location());
	}
}

std::string FileHandle::readLine(const std::string& filepath, unsigned int lineNumber) {
	std::string fileData;
	std::ifstream f(filepath);
	if (f.is_open()) {
		std::string line;
		unsigned int counter = 0;
		while (std::getline(f, line)) {
			if (counter == lineNumber) {
				fileData = line;
				break;
			}
			counter++;
		}
		f.close();
		return fileData;
	}
	else {
		throw PanicException(IOException("unable to perform io operation on file '" + filepath + "'; file not found or unable to open", location()), location());
	}
}

unsigned int FileHandle::countLines(const std::string& filepath) {
	std::ifstream f(filepath);
	if (f.is_open()) {
		std::string line;
		unsigned int counter = 0;
		while (std::getline(f, line)) {
			counter++;
		}
		f.close();
		return counter;
	}
	else {
		throw PanicException(IOException("unable to perform io operation on file '" + filepath + "'; file not found or unable to open", location()), location());
	}
}

std::string FileHandle::readFileAsString(const std::string& filepath)
{
	std::string fileData{ "" };
	std::ifstream f(filepath);
	if (f.is_open()) {
		std::string line;
		while (std::getline(f, line)) {
			fileData += line + "\n";
		}
		f.close();
		return fileData;
	}
	else {
		throw PanicException(IOException("unable to perform io operation on file '" + filepath + "'; file not found or unable to open", location()), location());
	}
}


void FileHandle::writeToFile(const std::string& filepath, std::vector<std::string> data, bool overwriteContents) {
	std::ofstream f(filepath, overwriteContents ? std::ofstream::out : std::ofstream::out | std::ofstream::app);
	if (f.is_open()) {
		for (unsigned int i{ 0 }; i < data.size(); i++) {
			f << data[i] << "\n";
		}
		f.close();
		return;
	}
	else {
		throw PanicException(IOException("unable to perform io operation on file '" + filepath + "'; file not found or unable to open", location()), location());
	}
}

void FileHandle::writeLine(const std::string& filepath, std::string data, bool overwriteContents) {
	std::ofstream f(filepath, overwriteContents? std::ofstream::out : std::ofstream::out | std::ofstream::app);
	if (f.is_open()) {
		f << data;
		f.close();
		return;
	}
	else {
		throw PanicException(IOException("unable to perform io operation on file '" + filepath + "'; file not found or unable to open", location()), location());
	}
}



#endif