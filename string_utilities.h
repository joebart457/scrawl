#pragma once

#ifndef __STRING_UTIL_H
#define __STRING_UTIL_H

#include <string>
#include <vector>

bool contains(const std::string& s, const std::string& match);

std::vector<std::string> split(const std::string& s, char delimiter);

std::string lower(const std::string& s);

#endif