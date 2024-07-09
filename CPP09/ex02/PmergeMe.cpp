#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    std::cout << BLACK << "| Def. C |" << RESET << std::endl;
}

PmergeMe::PmergeMe(std::vector<int> base) : _vec(base),
                                            _dque(base.begin(), base.end()),
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

std::vector<int> PmergeMe::getVec()
{
    return this->_vec;
}

std::deque<int> PmergeMe::getDque()
{
    return this->_dque;
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

void PmergeMe::initDoubleDeque(std::deque<std::pair<int, int> > *doubleDeque)
{
    for (int i = 0; i < this->_nArgs; i += 2)
    {
        if (i + 1 < this->_nArgs)
            doubleDeque->push_back(std::make_pair(this->_dque[i], this->_dque[i + 1]));
        else
            this->_oddArgVal = this->_dque[i];
    }
    for (size_t i = 0; i < doubleDeque->size(); ++i)
    {
        if ((*doubleDeque)[i].first < (*doubleDeque)[i].second)
            std::swap((*doubleDeque)[i].first, (*doubleDeque)[i].second);
    }
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

void PmergeMe::sortDoubleDqueRecursive(std::deque<std::pair<int, int> > *doubleDeque, int dqueSize)
{
    if (dqueSize == 1)
        return;
    sortDoubleDqueRecursive(doubleDeque, dqueSize - 1);
    int lastFirst = (*doubleDeque)[dqueSize - 1].first;
    int lastSecond = (*doubleDeque)[dqueSize - 1].second;
    int i = dqueSize - 2;
    while (i >= 0 && (*doubleDeque)[i].first > lastFirst)
    {
        (*doubleDeque)[i + 1].first = (*doubleDeque)[i].first;
        (*doubleDeque)[i + 1].second = (*doubleDeque)[i].second;
        i--;
    }
    (*doubleDeque)[i + 1].first = lastFirst;
    (*doubleDeque)[i + 1].second = lastSecond;
}

int PmergeMe::get_jacobsthalN(int n)
{
    if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return get_jacobsthalN(n - 1) + 2 * get_jacobsthalN(n - 2);
}

void PmergeMe::insertSortedVec(std::vector<std::pair<int, int> > *doubleVec)
{
    int oldDist = 0;
    this->_vec.push_back((*doubleVec)[0].second);
    this->_vec.push_back((*doubleVec)[0].first);
    for (size_t i = 1; i < doubleVec->size(); ++i)
    {
        this->_vec.push_back((*doubleVec)[i].first);
    }
    // Iteration from the doubleVec
    for (size_t i = 2; i < (*doubleVec).size(); i++) {
        int dist = std::abs(get_jacobsthalN(i) - get_jacobsthalN(i + 1));
        // Iteration from the distance with the jacobsthal
        for (size_t j = 0 + dist; j > 0; j--) {
            if (j + oldDist < (*doubleVec).size()) {
                int numberToInsert = (*doubleVec)[j + oldDist].second;
                int vecSize = this->_vec.size();
                // Iteration from the vector to get the size
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
    int vecSize = this->_vec.size();
    if (this->_nArgs % 2 != 0) {
        for (int i = 0; i < vecSize; i++) {
            if (this->_oddArgVal < this->_vec[i]) {
                this->_vec.insert(this->_vec.begin() + i, this->_oddArgVal);
                i = vecSize;
            }
        }
    }
}

void PmergeMe::insertSortedDque(std::deque<std::pair<int, int> > *doubleDeque)
{
    int oldDist = 0;
    this->_dque.push_back((*doubleDeque)[0].second);
    this->_dque.push_back((*doubleDeque)[0].first);
    for (size_t i = 1; i < doubleDeque->size(); ++i)
    {
        this->_dque.push_back((*doubleDeque)[i].first);
    }
    // Iteration from the doubleDeque
    for (size_t i = 2; i < (*doubleDeque).size(); i++) {
        int dist = std::abs(get_jacobsthalN(i) - get_jacobsthalN(i + 1));
        // Iteration from the distance with the jacobsthal
        for (size_t j = 0 + dist; j > 0; j--) {
            if (j + oldDist < (*doubleDeque).size()) {
                int numberToInsert = (*doubleDeque)[j + oldDist].second;
                int dqueSize = this->_dque.size();
                // Iteration from the vector to get the size
                for (int l = 0; l < dqueSize; l++) {
                    if (numberToInsert < this->_dque[l]) {
                        this->_dque.insert(this->_dque.begin() + l, numberToInsert);
                        l = dqueSize;
                    } else if (l + 1 == dqueSize) {
                        this->_dque.insert(this->_dque.begin() + l + 1, numberToInsert);
                    }
                }
            }
        }
        oldDist = dist;
    }
    int dqueSize = this->_dque.size();
    if (this->_nArgs % 2 != 0) {
        for (int i = 0; i < dqueSize; i++) {
            if (this->_oddArgVal < this->_dque[i]) {
                this->_dque.insert(this->_dque.begin() + i, this->_oddArgVal);
                i = dqueSize;
            }
        }
    }
}

void PmergeMe::vecsort()
{
    std::vector<std::pair<int, int> > doubleVec;

    initDoubleVec(&doubleVec);
    this->_vec.clear();
    sortDoubleVecRecursive(&doubleVec, doubleVec.size());
    insertSortedVec(&doubleVec);
}

void PmergeMe::dquesort()
{
    std::deque<std::pair<int, int> > doubleDeque;

    initDoubleDeque(&doubleDeque);
    this->_dque.clear();
    sortDoubleDqueRecursive(&doubleDeque, doubleDeque.size());
    insertSortedDque(&doubleDeque);
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

void PmergeMe::printDoubleDeque(const std::deque<std::pair<int, int> > &dQue)
{
    if (dQue.size() > 0)
    {
        std::cout << "| ";
        for (std::deque<std::pair<int, int> >::const_iterator it = dQue.begin(); it != dQue.end(); ++it)
        {
            std::cout << "a: " << it->first << "\t| ";
        }
        std::cout << "\n| ";
        for (std::deque<std::pair<int, int> >::const_iterator it = dQue.begin(); it != dQue.end(); ++it)
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