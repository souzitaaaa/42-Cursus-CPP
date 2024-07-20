#include "BitcoinExchange.hpp"

bool checkYear(std::string token, int &year)
{
    for (size_t i = 0; i < token.length(); i++)
    {
        if (!isdigit(token[i]))
            return true;
    }
    int aux = std::atoi(token.c_str());
    if (!(aux >= 2009))
        return true;
    year = aux;
    return false;
}

bool checkMonthDay(std::string token_md, int year)
{
    std::istringstream md(token_md);
    std::string token;
    int month;
    for (int i = 0; i < 2; i++)
    {
        i == 0
            ? std::getline(md, token, '-')
            : std::getline(md, token);
        if (token.empty())
            return true;
        if (i == 0)
        {
            for (size_t i = 0; i < token.length(); i++)
            {
                if (!isdigit(token[i]))
                    return true;
            }
            int aux = std::atoi(token.c_str());
            if (!(aux >= 1 && aux <= 12))
                return true;
            month = aux;
        }
        else
        {
            for (size_t i = 0; i < token.length(); i++)
            {
                if (!isdigit(token[i]))
                {
                    if (i + 1 == token.length())
                        continue;
                    else
                        return true;
                }
            }
            int aux = std::atoi(token.c_str());
            if (month == 1 || month == 3 || month == 5 ||
                month == 7 || month == 8 || month == 10 || month == 12)
            {
                if (year == 2009 && month == 1 && !(aux >= 2 && aux <= 31))
                    return true;
                else if (!(aux >= 1 && aux <= 31))
                    return true;
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11)
            {
                if (!(aux >= 1 && aux <= 30))
                    return true;
            }
            else
            {
                if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                {
                    if (!(aux >= 1 && aux <= 29))
                        return true;
                }
                else
                {
                    if (!(aux >= 1 && aux <= 28))
                        return true;
                }
            }
        }
    }
    return false;
}

bool checkDate(std::string date)
{
    if (date.empty())
        return true;
    std::istringstream ymd(date);
    std::string token;
    bool out;
    int year;
    for (int i = 0; i < 2; i++)
    {
        i == 0
            ? std::getline(ymd, token, '-')
            : std::getline(ymd, token);
        i == 0
            ? out = checkYear(token, year)
            : out = checkMonthDay(token, year);
        if (out)
            return true;
    }
    return false;
}

std::string iterate(std::string str, int *i, char target)
{
    while (str[*i] == target)
        (*i)++;
    return (str.substr(*i));
}

bool isInt(std::string arg)
{
    int i = 0;
    iterate(arg, &i, ' ');
    if (arg[i] == '+')
        i++;
    else if (arg[i] == '-')
    {
        std::cout << RED << "Error:" << RESET
                  << " not a positive number" << std::endl;
        return true;
    }
    std::string argTrimmed = arg.substr(i);
    for (unsigned long i = 0; i < argTrimmed.length(); i++)
    {
        if (!std::isdigit(argTrimmed[i]))
            return false;
    }
    long argInt = std::atol(arg.c_str());
    if (argInt < 0 || argInt > 1000)
    {
        std::cout << RED << "Error:" << RESET
                  << " too large a number" << std::endl;
        return true;
    }
    return false;
}

bool isFloat(std::string arg)
{
    int i = 0;
    bool onePoint = false;
    iterate(arg, &i, ' ');
    if (arg[i] == '+')
        i++;
    else if (arg[i] == '-')
    {
        std::cout << RED << "Error:" << RESET
                  << " not a positive number" << std::endl;
        return true;
    }
    std::string argTrimmed = arg.substr(i);
    for (unsigned long i = 0; i < argTrimmed.length(); i++)
    {
        if (!std::isdigit(argTrimmed[i]))
        {
            if (argTrimmed[i] == '.' && !onePoint)
                onePoint = true;
            else
            {
                std::cout << RED << "Error:" << RESET
                          << " bad value format" << std::endl;
                return true;
            }
        }
    }
    double argDouble = std::atof(arg.c_str());
    if (argDouble < 0 || argDouble > 1000)
    {
        std::cout << RED << "Error:" << RESET
                  << " too large a number" << std::endl;
        return true;
    }
    return false;
}

bool checkExcR(std::string n_btc)
{
    bool out = false;
    bool (*f[])(std::string) = {&isInt, &isFloat};
    for (unsigned long i = 0; i < ARR_SIZE(f); i++)
    {
        if ((out = f[i](n_btc)))
            return true;
    }
    return false;
}

void validateHeaderInput(std::istringstream &l)
{
    std::string val;
    std::getline(l, val, '|');
    if (val.compare("date "))
        throw InputFileHeaderError();
    std::getline(l, val);
    if (val.compare(" value"))
        throw InputFileHeaderError();
}

void getInformation(std::istringstream &l, BitcoinExchange &btc)
{
    (void)btc;
    std::string date;
    std::string n_btc;
    std::getline(l, date, '|');
    std::getline(l, n_btc, '|');
    if (checkDate(date))
    {
        std::cout << RED << "Error:" << RESET
                  << " bad input => " << date << std::endl;
        return;
    }
    if (checkExcR(n_btc))
        return;
    std::cout << YELLOW << date << RESET << " => " << n_btc << " = "
              << GREEN << btc.getValue(date, n_btc) << RESET << std::endl;
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::cout << YELLOW << "------------------BTC------------------" << RESET << std::endl;
        try
        {
            BitcoinExchange btc;
            std::string line;
            std::ifstream inputF(argv[1]);
            if (!inputF || (inputF.peek() == std::ifstream::traits_type::eof()))
                throw InputFileError();

            for (int i = 0; std::getline(inputF, line); i++)
            {
                std::istringstream l(line);
                i == 0
                    ? validateHeaderInput(l)
                    : getInformation(l, btc);
            }
            inputF.close();
        }
        catch (const std::exception &e)
        {
            // Verificar leaks pk n esta a chamar o destrutor
            std::cout << RED << e.what() << RESET;
        }
    }
    else
    {
        std::cout << RED << WRONG_ARGS << RESET << std::endl;
    }
}