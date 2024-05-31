#ifndef LIBFT_HPP
#define LIBFT_HPP

#include "ScalarConverter.hpp"
#include <limits.h>
#include <float.h>

class Libft
{
private:
    Libft();

public:
    ~Libft();

    // Get Type of arguments --------------------------------
    static int getType(std::string arg);
    static bool isChar(std::string arg);
    static bool isInt(std::string arg);
    static bool isFloat(std::string arg);
    static bool isDouble(std::string arg);
    // Aux --------------------------------------------------
    static void iterate(std::string str, int *i);
};

#endif
