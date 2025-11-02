#include "../includes/BitcoinExchange.hpp"
#include "../includes/date_utils.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <cfloat>

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const std::string& filename)
{
	try
	{
		FillMap(filename);
	}
	catch(const std::exception& e)
	{
		throw;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->data = other.data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		this->data = other.data;
	return *this;
}

BitcoinExchange::~BitcoinExchange(){};

void BitcoinExchange::FillMap(const std::string& filename)
{
	std::fstream	infile(filename.c_str());
	if (!infile.is_open())
		throw std::runtime_error("Error: could not open data file.");
	std::string		line,date,value;

	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		if (BitcoinExchange::ParseLine(line, date, value))
		{
			long long key = date_utils::ToDate(date);
			double val = strtod(value.c_str(), NULL);
			data[key] = val;
		}
		else
		{
			std::cerr << "in data file: \"" << line << "\"\n";
			throw std::runtime_error("Error: invalid data file.");
		}
	}
}

void BitcoinExchange::Convert(long long date, double value)
{
	std::map<long long, double>::iterator it = data.lower_bound(date);
	if (it == data.end())
		--it;
	else if (it->first != date && it != data.begin())
		--it;
	double result = value * it->second;
	std::cout << date / 10000 << "-" << (date / 100) % 100 << "-" << date % 100
			<< " => " << value << " = " << result << "\n";
}
bool BitcoinExchange::ParseLine(const std::string& line, std::string& date, std::string& value)
{
	std::string::size_type pos = line.find('|');
	if (pos == std::string::npos)
		pos = line.find(',');
	if(pos == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << " ";
		return false;
	}
	date = line.substr(0, pos);
	value = line.substr(pos + 1);
	while (!date.empty() && std::isspace(date[date.size() - 1])) date.erase(date.size() - 1);
	while (!date.empty() && std::isspace(date[0])) date.erase(0,1);
	while (!value.empty() && std::isspace(value[value.size() - 1])) value.erase(value.size() - 1);
	while (!value.empty() && std::isspace(value[0])) value.erase(0, 1);
	return date_utils::IsValidDate(date) && BitcoinExchange::IsValidValue(value);
}

bool BitcoinExchange::IsValidValue(const std::string& valueStr)
{
	if (valueStr.empty())
	{
		std::cerr << "Error: missing value ";
		return false;
	}
	char* end;
	double val = strtod(valueStr.c_str(), &end);
	if (*end != '\0' || val < 0.0 || val >= FLT_MAX || errno == ERANGE)
	{
		std::cerr << "Error: invalid value => " << valueStr << " ";
		return false;
	}
	return true;
}