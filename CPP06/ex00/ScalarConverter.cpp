#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}
//TODO oque fazer com o cpy
ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
	(void)cpy;
	std::cout << YELLOW << "Copy Buconstructor called" << RESET << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &cpy)
{
	std::cout << "Copy operator called" << std::endl;
	if (this == &cpy)
		return *this;
	return *this;
}

int ScalarConverter::getArgType(char *argument) {
	(void)argument;
	return 1;
}

void ScalarConverter::convert(char *argument) {
	try {
		int type = ScalarConverter::getArgType(argument);
	} catch(const std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
	}
}

ScalarConverter::~ScalarConverter()
{
	std::cout << BLACK << "Destructor called" << RESET << std::endl;
}