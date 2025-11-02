#pragma once
#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<long long, double> data;
		BitcoinExchange();
		void FillMap(const std::string& filename);
		bool ParseLine(const std::string& line, std::string& date, std::string& value);
		bool IsValidValue(const std::string& valueStr);
	public:
		BitcoinExchange(const std::string& filename);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		void Convert(long long date, double value);
};
