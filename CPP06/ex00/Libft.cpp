#include "Libft.hpp"

Libft::Libft() {}

/**
 * @param   arg -> Argument to be checked
 * @return  Char: 0, Int: 1, Float: 2, Double: 3
 */
int Libft::getType(std::string arg) {
    if (arg.empty())
        return -1;
    std::cout << RED << "ARG: " << arg << RESET << std::endl;
    bool out = false;
    bool (*f[])(std::string) = {&isChar, &isInt, &isFloat, &isDouble};
    for (unsigned long i = 0; i < sizeof(f) / sizeof(f[0]); i++) {
        if ((out = f[i](arg)))
            return i;
    }
    return -1;
}

bool Libft::isChar(std::string arg) {
    if (arg.length() >= 2 || std::isdigit(arg[0])
        || !std::isprint(arg[0]))
        return false;
    return true;
}

bool Libft::isInt(std::string arg) {
    int i = 0;
    Libft::iterate(arg, &i);
    if (arg[i] == '-' || arg[i] == '+' ) 
        i++;
    std::string argTrimmed = arg.substr(i);
    for (unsigned long i = 0; i < argTrimmed.length(); i++) {
        if (!std::isdigit(argTrimmed[i]))
            return false;
    }
    long argInt = std::atol(arg.c_str());
    if (argInt < INT_MIN || argInt > INT_MAX)
        return false;
    return true;
}

bool Libft::isFloat(std::string arg) {
    int i = 0;
    bool onePoint = false;
    bool oneF = false;
    Libft::iterate(arg, &i);
    if (arg[i] == '-' || arg[i] == '+' ) 
        i++;
    std::string argTrimmed = arg.substr(i);
    for (unsigned long i = 0; i < argTrimmed.length(); i++) {
        if (!std::isdigit(argTrimmed[i])) {
            if (argTrimmed[i] == '.' && !onePoint)
                onePoint = true;
            else if ((argTrimmed[i] == 'f' || argTrimmed[i] == 'F')
                && i + 1 ==  argTrimmed.length())
                oneF = true;
            else
                return false;
        }
    }
    if (!oneF)
        return false;
    double argDouble = std::atof(arg.c_str());
    if (argDouble < FLT_MIN || argDouble > FLT_MAX)
        return false;
    return true;
}

bool Libft::isDouble(std::string arg) {
    int i = 0;
    bool onePoint = false;
    Libft::iterate(arg, &i);
    if (arg[i] == '-' || arg[i] == '+' ) 
        i++;
    std::string argTrimmed = arg.substr(i);
    for (unsigned long i = 0; i < argTrimmed.length(); i++) {
        if (!std::isdigit(argTrimmed[i])) {
            if (argTrimmed[i] == '.' && !onePoint)
                onePoint = true;
            else
                return false;
        }
    }
    long double argLongDouble = std::strtold(arg.c_str(), NULL);
    if (argLongDouble < DBL_MIN || argLongDouble > DBL_MAX)
        return false;
    return true;
}

/**
 * @param   str ->  String to iterate
 * @param   i   ->  Variable to store the times it iterates
 */
void Libft::iterate(std::string str, int *i) {
    while (std::isspace(str[*i]))
        (*i)++;
}

Libft::~Libft() {}