#pragma once
#include <string>

namespace date_utils
{
	bool ParseLine(const std::string& line, std::string& date, std::string& value);
	bool IsValidDate(const std::string& date);
	bool IsLeapYear(int year);
	bool IsValidValue(const std::string& value);
	long long ToDate(const std::string& date);
}