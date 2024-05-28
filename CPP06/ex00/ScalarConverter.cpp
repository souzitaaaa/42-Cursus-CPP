#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

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

/*
const char *ScalarConverter::GradeTooHighException::what() const throw()
{
	return ("❌ To high of a grade to assign");
}*/

ScalarConverter::~ScalarConverter()
{
	std::cout << BLACK << "Destructor called" << RESET << std::endl;
}