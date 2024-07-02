#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << BLACK << "| Def. C |" << RESET << std::endl;
    parseFile();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) : _db(cpy._db)
{
    std::cout << BLACK << "| Copy C |" << RESET << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
    std::cout << BLACK << "| Assign. O |" << RESET << std::endl;
    if (this == &cpy)
        return *this;
    this->_db = cpy._db;
    return *this;
}

void BitcoinExchange::parseFile()
{
    std::ifstream dbFile("data.csv");
    if (!dbFile)
        throw BitcoinExchangeException("Error opening [data.csv]");

    std::string line;
    std::getline(dbFile, line);
    while (std::getline(dbFile, line))
    {
        std::istringstream l(line);
        std::string val;

        std::getline(l, val, ',');
        std::string date = val;

        std::getline(l, val);
        float ex_rate = std::atof(val.c_str());

        this->_db[date] = ex_rate;
    }
    dbFile.close();
};

void BitcoinExchange::printExchangeRate(const std::string date) const
{
    std::map<std::string, float>::const_iterator it = _db.find(date);
    it != _db.end()
        ? std::cout << it->first << " = " << it->second << std::endl
        : std::cerr << "Date not found in database" << std::endl;
}

float BitcoinExchange::getValue(std::string key, std::string n_btc)
{
    std::map<std::string, float>::const_iterator it = _db.lower_bound(key);
    if (it != _db.end())
    {
        --it;
        float exc_r = it->second;
        return (std::atof(n_btc.c_str()) * exc_r);
    }
    else
        return 0;
}

BitcoinExchange::BitcoinExchangeException::BitcoinExchangeException(const std::string &message) : _message(message) {}

const char *BitcoinExchange::BitcoinExchangeException::what() const throw()
{
    return _message.c_str();
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << BLACK << "| Dest. |" << RESET << std::endl;
}