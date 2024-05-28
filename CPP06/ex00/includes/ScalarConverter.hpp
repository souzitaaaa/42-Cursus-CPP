#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

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
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\e[0;36m"
#define YELLOW "\e[0;33m"
#define BLACK "\033[0;30m"
#define RESET "\033[0m"

class ScalarConverter
{

private:

public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &cpy);
	ScalarConverter &operator=(const ScalarConverter &cpy);
	~ScalarConverter();

	/*class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};*/
};

#endif