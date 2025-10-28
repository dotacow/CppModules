#pragma once
#include <map>
#include <sstream>
#include <string>
#include <fstream>

class BitcoinExchange
{
	private:
		std::map<std::string, float> data;
		BitcoinExchange();
	public:
		BitcoinExchange(const std::string& filename);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		void FillMap(const std::string& filename);
};