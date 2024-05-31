#include "ScalarConverter.hpp"

int main(int av, char **ac)
{
    try {
        if (av > 2 || av == 1)
            throw Exception(WRONG_ARGS);
        ScalarConverter::convert(ac[1]);
    } catch(const std::exception& e){
        std::cout << RED << e.what() << RESET << std::endl;
    }
}