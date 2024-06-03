#include "ScalarConverter.hpp"
#include "Libft.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

//TODO oque fazer com o cpy
ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
	(void)cpy;
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &cpy)
{
	std::cout << "Copy operator called" << std::endl;
	if (this == &cpy)
		return *this;
	return *this;
}


void ScalarConverter::convert(char *argument) {
	try {
		int type = Libft::getType(argument);
		if (type == -1)
            throw Exception(WRONG_TYPE);
    	void (*f[])(std::string) = {&Libft::convertChar, &Libft::convertInt,
									&Libft::convertFloat, &Libft::convertDouble,
									&Libft::convertInf, &Libft::convertNan};
        f[type](argument);
	} catch(const std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
	}
}

ScalarConverter::~ScalarConverter()
{
	std::cout << BLACK << "Destructor called" << RESET << std::endl;
}