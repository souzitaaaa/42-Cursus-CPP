#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    std::cout << BLACK << "| Def. C |" << RESET << std::endl;
}

PmergeMe::PmergeMe(std::vector<int> base) : _vec(base),
                                            _lst(base.begin(), base.end()),
                                            _nArgs(base.size()),
                                            _oddArgVal(-1)
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
        if (i + 1 < this->_nArgs)
            doubleVec->push_back(std::make_pair(this->_vec[i], this->_vec[i + 1]));
        else
            this->_oddArgVal = this->_vec[i];
    }
    for (size_t i = 0; i < doubleVec->size(); ++i)
    {
        if ((*doubleVec)[i].first < (*doubleVec)[i].second)
            std::swap((*doubleVec)[i].first, (*doubleVec)[i].second);
    }
}

std::vector<int> PmergeMe::getVec()
{
    return this->_vec;
}

void PmergeMe::sortDoubleVecRecursive(std::vector<std::pair<int, int> > *doubleVec, int vecSize)
{
    if (vecSize == 1)
        return;
    sortDoubleVecRecursive(doubleVec, vecSize - 1);
    int lastFirst = (*doubleVec)[vecSize - 1].first;
    int lastSecond = (*doubleVec)[vecSize - 1].second;
    int i = vecSize - 2;
    while (i >= 0 && (*doubleVec)[i].first > lastFirst)
    {
        (*doubleVec)[i + 1].first = (*doubleVec)[i].first;
        (*doubleVec)[i + 1].second = (*doubleVec)[i].second;
        i--;
    }
    (*doubleVec)[i + 1].first = lastFirst;
    (*doubleVec)[i + 1].second = lastSecond;
}

int PmergeMe::get_jacobsthalN(int n)
{
    if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return get_jacobsthalN(n - 1) + 2 * get_jacobsthalN(n - 2);
}

void PmergeMe::insertSorted(std::vector<std::pair<int, int> > *doubleVec)
{
    int oldDist = 0;
    this->_vec.push_back((*doubleVec)[0].second);
    this->_vec.push_back((*doubleVec)[0].first);
    for (size_t i = 1; i < doubleVec->size(); ++i)
    {
        this->_vec.push_back((*doubleVec)[i].first);
    }
    for (size_t i = 2; i < (*doubleVec).size(); i++) {
        int dist = std::abs(get_jacobsthalN(i) - get_jacobsthalN(i + 1));
        for (size_t j = 0 + dist; j > 0; j--) {
            if (j + oldDist < (*doubleVec).size()) {
                int numberToInsert = (*doubleVec)[j + oldDist].second;
                int vecSize = this->_vec.size();
                for (int l = 0; l < vecSize; l++) {
                    if (numberToInsert < this->_vec[l]) {
                        this->_vec.insert(this->_vec.begin() + l, numberToInsert);
                        l = vecSize;
                    } else if (l + 1 == vecSize) {
                        this->_vec.insert(this->_vec.begin() + l + 1, numberToInsert);
                    }
                }
            }
        }
        oldDist = dist;
    }
}

void PmergeMe::vecsort()
{
    std::vector<std::pair<int, int> > doubleVec;

    initDoubleVec(&doubleVec);
    this->_vec.clear();
    std::cout << CYAN << "After init" << RESET << std::endl;
    printDoubleVec(doubleVec);
    sortDoubleVecRecursive(&doubleVec, doubleVec.size());
    std::cout << CYAN << "After insertion sort recursive" << RESET << std::endl;
    printDoubleVec(doubleVec);
    insertSorted(&doubleVec);
}

void PmergeMe::printDoubleVec(const std::vector<std::pair<int, int> > &dVec)
{
    if (dVec.size() > 0)
    {
        std::cout << "| ";
        for (std::vector<std::pair<int, int> >::const_iterator it = dVec.begin(); it != dVec.end(); ++it)
        {
            std::cout << "a: " << it->first << "\t| ";
        }
        std::cout << "\n| ";
        for (std::vector<std::pair<int, int> >::const_iterator it = dVec.begin(); it != dVec.end(); ++it)
        {
            std::cout << "b: " << it->second << "\t| ";
        }
        if (this->_oddArgVal != -1)
            std::cout << "b: " << this->_oddArgVal << "\t| ";
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