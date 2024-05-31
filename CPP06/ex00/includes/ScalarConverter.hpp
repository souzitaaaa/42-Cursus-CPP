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
# include "Libft.hpp"

class Libft;

class ScalarConverter
{

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &cpy);
	ScalarConverter &operator=(const ScalarConverter &cpy);

public:
	~ScalarConverter();

	static void convert(char *);
};

#endif