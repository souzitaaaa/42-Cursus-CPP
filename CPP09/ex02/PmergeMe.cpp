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

void PmergeMe::initDoubleVec(std::vector<std::pair<int, int> > *doubleVec)
{
    for (int i = 0; i < this->_nArgs; i += 2)
    {
        i + 1 < this->_nArgs
            ? doubleVec->push_back(std::make_pair(this->_vec[i], this->_vec[i + 1]))
            : doubleVec->push_back(std::make_pair(this->_vec[i], -1));
    }
    for (size_t i = 0; i < doubleVec->size(); ++i)
    {
        if ((*doubleVec)[i].first > (*doubleVec)[i].second)
            std::swap((*doubleVec)[i].first, (*doubleVec)[i].second);
    }
}

void PmergeMe::vecsort()
{
    std::vector<std::pair<int, int> > doubleVec;

    initDoubleVec(&doubleVec);
    printDoubleVec(doubleVec);
}

void PmergeMe::printDoubleVec(const std::vector<std::pair<int, int> > &dVec)
{
    if (dVec.size() > 0)
    {
        std::cout << "| ";
        for (std::vector<std::pair<int, int> >::const_iterator it = dVec.begin(); it != dVec.end(); ++it)
        {
            std::cout << "(a: " << it->first << ",b: " << it->second << ") | ";
        }
        std::cout << std::endl;
    }
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