#pragma once
#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<long long, float> data;
		BitcoinExchange();
	public:
		BitcoinExchange(const std::string& filename);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		void FillMap(const std::string& filename);
};