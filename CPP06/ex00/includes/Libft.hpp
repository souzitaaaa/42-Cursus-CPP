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
    static std::string iterate(std::string str, int *i, char target);
    
    
    
    
    // Only for this exercise (remove later) --------------------------------
    static void convertChar(std::string arg);
    static void convertInt(std::string arg);
    static void convertFloat(std::string arg);
    static void convertDouble(std::string arg);
    static void convertPseudoFloat(std::string arg);
    static void convertPseudoDouble(std::string arg);
};

#endif