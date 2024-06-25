#include "Span.hpp"

Span::Span() : _maxN(0)
{
    std::cout << BLACK << "| Def. C |" << RESET << std::endl;
    this->_vec.reserve(0);
}

Span::Span(unsigned int maxN) : _maxN(maxN)
{
    std::cout << BLACK << "| Param. C |" << RESET << std::endl;
}

Span::Span(const Span &cpy) : _maxN(cpy._maxN),
                              _vec(cpy._vec)
{
    std::cout << BLACK << "| Copy C |" << RESET << std::endl;
}

Span &Span::operator=(const Span &cpy)
{
    std::cout << BLACK << "| Assign. O |" << RESET << std::endl;
    if (this == &cpy)
        return *this;
    this->_maxN = cpy._maxN;
    this->_vec = cpy._vec;
    return *this;
}

unsigned int Span::getMaxN() const
{
    return this->_maxN;
}

std::vector<int> Span::getVec() const
{
    return this->_vec;
}

std::vector<int> Span::getVec()
{
    return this->_vec;
}

void Span::addNumber(int val)
{
    if (this->_vec.size() == this->_maxN)
        throw ContainerMax();
    this->_vec.push_back(val);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (this->_vec.size() + std::distance(begin, end) > this->_maxN)
        throw ContainerMax();
    this->_vec.insert(this->_vec.end(), begin, end);
}

int Span::shortestSpan()
{
    if (this->_vec.size() <= 1)
        throw NoSpanFound();
    int out = 0;
    std::sort(this->_vec.begin(), this->_vec.end());
    int aux = std::abs(this->_vec.at(1) - this->_vec.at(0));
    out = aux;
    for (unsigned int i = 1; i + 1 < this->_maxN; i++)
    {
        aux = std::abs(this->_vec.at(i + 1) - this->_vec.at(i));
        if (aux < out)
            out = aux;
    }
    return out;
};

int Span::longestSpan()
{
    if (this->_vec.size() <= 1)
        throw NoSpanFound();
    int minNumber = *std::min_element(this->_vec.begin(), this->_vec.end());
    int maxNumber = *std::max_element(this->_vec.begin(), this->_vec.end());

    return maxNumber - minNumber;
};

Span::~Span()
{
    std::cout << BLACK << "| Dest. |" << RESET << std::endl;
}