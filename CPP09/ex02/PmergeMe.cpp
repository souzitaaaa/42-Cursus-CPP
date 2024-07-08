#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    std::cout << BLACK << "| Def. C |" << RESET << std::endl;
}

PmergeMe::PmergeMe(std::vector<int> base) : _vec(base),
                                            _lst(base.begin(), base.end()),
                                            _nArgs(base.size())
{
    std::cout << BLACK << "| Params C |" << RESET << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &cpy)
{
    (void)cpy;
    std::cout << BLACK << "| Copy C |" << RESET << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &cpy)
{
    std::cout << BLACK << "| Assign. O |" << RESET << std::endl;
    if (this == &cpy)
        return *this;
    return *this;
}

PmergeMe::PmergeMeException::PmergeMeException(const std::string &message) : _message(message) {}

const char *PmergeMe::PmergeMeException::what() const throw()
{
    return _message.c_str();
}

PmergeMe::~PmergeMe()
{
    std::cout << BLACK << "| Dest. |" << RESET << std::endl;
}