#include "../includes/BitcoinExchange.hpp"

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

