#include "../includes/date_utils.hpp"
#include "../includes/BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc input_file\n";
		return (1);
	}
	try
	{
		BitcoinExchange	btc("data.csv");
		std::fstream	infile(argv[1]);
		if (!infile.is_open())
			throw std::runtime_error("Error: could not open input file.");
		std::string		line,date,value;
		int i = 1;

		while (std::getline(infile, line))
		{
			long long key;
			double		val;

			if (!date_utils::ParseLine(line, date, value))
				std::cerr << "Error: bad input at line " << i << ": \"" << line << "\"\n";
			else
			{
				key = date_utils::ToDate(date);
				val = strtod(value.c_str(), NULL);
				btc.Convert(key, val);
			}
			i++;
		}
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
	return 0;
}
