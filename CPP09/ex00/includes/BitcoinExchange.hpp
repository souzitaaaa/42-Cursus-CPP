#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <map>
#include <sstream>
#include <limits.h>
#include <float.h>
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\e[0;36m"
#define YELLOW "\e[0;33m"
#define BLACK "\033[0;30m"
#define RESET "\033[0m"
#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define WRONG_ARGS "Error: could not open file"

class BitcoinExchange
{
private:
	std::map<std::string, float> _db;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &cpy);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &cpy);

	void parseFile();
	void printExchangeRate(const std::string date) const;
	float getValue(std::string key, std::string n_btc);

	class BitcoinExchangeException : public std::exception
	{
	public:
		BitcoinExchangeException(const std::string &message);
		virtual const char *what() const throw();
		virtual ~BitcoinExchangeException() throw() {}

	private:
		std::string _message;
	};
};

class InputFileError : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return ("Error: could not open file\n");
	}
};

class InputFileHeaderError : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return ("Error on input file header\n");
	}
};

#endif