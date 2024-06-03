#ifndef LIBFT_HPP
#define LIBFT_HPP

#include <limits.h>
#include <float.h>
#include <Serializer.hpp>

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
};

#endif