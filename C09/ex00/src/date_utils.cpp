#include <string>
#include <cctype>

namespace date_utils
{
	bool IsLeapYear(int year)
	{
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	bool IsValidDate(const std::string& date)
	{
		if (date.size() != 10 || date[4] != '-' || date[7] != '-')
			return false;

		int year = std::atoi(date.substr(0, 4).c_str());
		int month = std::atoi(date.substr(5, 2).c_str());
		int day = std::atoi(date.substr(8, 2).c_str());

		if (month < 1 || month > 12 || day < 1)
			return false;

		static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int dim = daysInMonth[month - 1];
		if (month == 2 && IsLeapYear(year))
			dim = 29;

		return day <= dim;
	}

	long long ToDate(const std::string& date)
	{
		int year = std::atoi(date.substr(0, 4).c_str());
		int month = std::atoi(date.substr(5, 2).c_str());
		int day = std::atoi(date.substr(8, 2).c_str());
		return static_cast<long long>(year) * 10000 + month * 100 + day;
	}

	bool IsValidValue(const std::string& valueStr)
	{
		if (valueStr.empty())
			return false;
		char* end;
		double val = std::strtod(valueStr.c_str(), &end);
		if (*end != '\0' || val < 0.0 || val > 1000.0 || errno == ERANGE)
			return false;
		return true;
	}

	bool ParseLine(const std::string& line, std::string& date, std::string& value)
	{
		std::string::size_type pos = line.find('|');
		if (pos == std::string::npos)
			return false;

		date = line.substr(0, pos);
		value = line.substr(pos + 1);

		while (!date.empty() && std::isspace(date[date.size() - 1])) date.erase(date.size() - 1);
		while (!date.empty() && std::isspace(date[0])) date.erase(0,1);
		
		while (!value.empty() && std::isspace(value[value.size() - 1])) value.erase(value.size() - 1);
		while (!value.empty() && std::isspace(value[0])) value.erase(0, 1);

		return IsValidDate(date) && IsValidValue(value);
	}
}
