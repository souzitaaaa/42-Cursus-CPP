#include "Libft.hpp"

Libft::Libft() {}

/**
 * @param   arg -> Argument to be checked
 * @return  Char: 0, Int: 1, Float: 2, Double: 3
 */
int Libft::getType(std::string arg) {
    if (arg.empty())
        return -1;
    if (!arg.compare("-inff") || !arg.compare("+inff") || !arg.compare("nanf"))
        return 4;
    if (!arg.compare("nan") || !arg.compare("-inf") || !arg.compare("+inf"))
        return 5;
    bool out = false;
    bool (*f[])(std::string) = {&isChar, &isInt, &isFloat, &isDouble};
    for (unsigned long i = 0; i < ARR_SIZE(f); i++) {
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
    Libft::iterate(arg, &i, ' ');
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
    Libft::iterate(arg, &i, ' ');
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
    if (!oneF || !onePoint)
        return false;
    double argDouble = std::atof(arg.c_str());
    if (argDouble < -FLT_MAX || argDouble > FLT_MAX)
        return false;
    return true;
}

bool Libft::isDouble(std::string arg) {
    int i = 0;
    bool onePoint = false;
    Libft::iterate(arg, &i, ' ');
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
    if (argLongDouble < -DBL_MAX || argLongDouble > DBL_MAX)
        return false;
    return true;
}

/**
 * @param   str ->  String to iterate
 * @param   i   ->  Variable to store the times it iterates
 * @return  Return the a substring iterated
 */
std::string Libft::iterate(std::string str, int *i, char target) {
    while (str[*i] == target)
        (*i)++;
    return (str.substr(*i));
}

void Libft::convertChar(std::string arg) {
    std::cout << YELLOW << "|\tChar Conversion\t\t|" << RESET << std::endl;
    std::cout << "CHAR:\t'" <<  arg[0] << "'" << std::endl;
    std::cout << "INT:\t" <<  static_cast<int>(arg[0]) <<  std::endl;
    std::cout << "FLOAT:\t" <<  std::fixed <<  static_cast<float>(arg[0]) << "f" << std::endl;
    std::cout << "DOUBLE:\t" <<  std::fixed <<  static_cast<double>(arg[0]) <<  std::endl;
}

void Libft::convertInt(std::string arg) {
    std::cout << YELLOW << "|\tInt Conversion\t\t|" << RESET << std::endl;
    int number = std::atoi(arg.c_str());
    if(number > 31 && number < 127)
        std::cout << "CHAR:\t'" << static_cast<char>(number) << "'" << std::endl;
    else if (number >= 0 && number <= 255)
        std::cout << "CHAR:\tNon displayable" << std::endl;
    else if (number < 0 || number > 255)
        std::cout << "CHAR:\tImpossible" << std::endl;
    std::cout << "INT:\t" <<  number <<  std::endl;
    std::cout << "FLOAT:\t" <<  std::fixed << static_cast<float>(number) << "f" <<  std::endl;
    std::cout << "DOUBLE:\t" <<  std::fixed <<  static_cast<double>(number) <<  std::endl;
}

void Libft::convertFloat(std::string arg) {
    std::cout << YELLOW << "|\tFloat Conversion\t|" << RESET << std::endl;
    float number = std::atof(arg.c_str());
    if(number > 31 && number < 127)
        std::cout << "CHAR:\t'" << static_cast<char>(number) << "'" << std::endl;
    else if (number >= 0 && number <= 255)
        std::cout << "CHAR:\tNon displayable" << std::endl;
    else if (number < 0 || number > 255)
        std::cout << "CHAR:\tImpossible" << std::endl;
    if(static_cast<long>(number) >= INT_MIN && static_cast<long>(number) <= INT_MAX)
        std::cout << "INT:\t" << static_cast<int>(number) << std::endl;
    else
        std::cout << "INT:\tImpossible" << std::endl;
    std::cout << "FLOAT:\t" << std::fixed <<  number << "f" << std::endl;
    std::cout << "DOUBLE:\t" << std::fixed << static_cast<double>(number) <<  std::endl;
}

void Libft::convertDouble(std::string arg) {
    std::cout << YELLOW << "|\tDouble Conversion\t|" << RESET << std::endl;
    double number = std::strtold(arg.c_str(), NULL);
    if(number > 31 && number < 127)
        std::cout << "CHAR:\t'" << static_cast<char>(number) << "'" << std::endl;
    else if (number >= 0 && number <= 255)
        std::cout << "CHAR:\tNon displayable" << std::endl;
    else if (number < 0 || number > 255)
        std::cout << "CHAR:\tImpossible" << std::endl;
    if(static_cast<long>(number) >= INT_MIN && static_cast<long>(number) <= INT_MAX)
        std::cout << "INT:\t" << static_cast<int>(number) << std::endl;
    else
        std::cout << "INT:\tImpossible" << std::endl;
    if(number >= -FLT_MAX && number <= FLT_MAX){
        std::cout << "FLOAT:\t" << std::fixed << static_cast<float>(number) << "f" << std::endl;
    }
    else
        std::cout << "FLOAT:\tImpossible" << std::endl;
    std::cout << "DOUBLE:\t" << std::fixed << number <<  std::endl;
}

void Libft::convertPseudoFloat(std::string arg) {
    std::cout << YELLOW << "|\tLiteral Conversion\t|" << RESET << std::endl;
    std::cout << "CHAR:\t" <<  "Impossible" << std::endl;
    std::cout << "INT:\t" <<  "Impossible" <<  std::endl;
    std::cout << "FLOAT:\t" <<  std::fixed <<  arg << std::endl;
    std::cout << "DOUBLE:\t" <<  std::fixed <<  arg.erase(arg.size() - 1) <<  std::endl;
}

void Libft::convertPseudoDouble(std::string arg) {
    std::cout << YELLOW << "|\tNan Conversion\t\t|" << RESET << std::endl;
    std::cout << "CHAR:\t" <<  "Impossible" << std::endl;
    std::cout << "INT:\t" <<  "Impossible" <<  std::endl;
    std::cout << "FLOAT:\t" <<  std::fixed << arg << "f" << std::endl;
    std::cout << "DOUBLE:\t" <<  std::fixed <<  arg <<  std::endl;
}

Libft::~Libft() {}