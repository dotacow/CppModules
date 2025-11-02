#include "../includes/BitcoinExchange.hpp"
#include "../includes/date_utils.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

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
		if (date_utils::ParseLine(line, date, value))
		{
			long long key = date_utils::ToDate(date);
			double val = strtod(value.c_str(), NULL);
			data[key] = val;
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