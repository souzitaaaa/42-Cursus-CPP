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

# include "Exception.hpp"
# include "Defines.hpp"

class ScalarConverter
{

private:

public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &cpy);
	ScalarConverter &operator=(const ScalarConverter &cpy);
	~ScalarConverter();

	static void convert(char *);
	static int getArgType(char *argument);
	/*class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};*/
};

#endif