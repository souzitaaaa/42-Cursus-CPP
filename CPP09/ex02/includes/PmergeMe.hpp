#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <stack>
#include <deque>
#include <list>
#include <queue>
#include <vector>
#include <sstream>
#include <limits.h>
#include <float.h>
#include <ctime>
#include <utility>
#include <sys/time.h>
#include <cstdlib>
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\e[0;36m"
#define YELLOW "\e[0;33m"
#define BLACK "\033[0;30m"
#define RESET "\033[0m"
#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define WRONG_ARGS "Error: Please try ./PmergeMe [list of numbers]"

class PmergeMe
{
private:
	std::vector<int> _vec;
	std::deque<int> _dque;
	int _nArgs;
	int _oddArgVal;

public:
	PmergeMe();
	PmergeMe(std::vector<int> base);
	PmergeMe(const PmergeMe &cpy);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &cpy);

	void vecsort();
	void initDoubleVec(std::vector<std::pair<int, int> > *doubleVec);
	void printDoubleVec(const std::vector<std::pair<int, int> > &dVec);
	void sortDoubleVecRecursive(std::vector<std::pair<int, int> > *doubleVec, int vecSize);
	void insertSortedVec(std::vector<std::pair<int, int> > *doubleVec);
	void dquesort();
	void initDoubleDeque(std::deque<std::pair<int, int> > *doubleDeque);
	void printDoubleDeque(const std::deque<std::pair<int, int> > &dQue);
	void sortDoubleDqueRecursive(std::deque<std::pair<int, int> > *doubleDeque, int dqueSize);
	void insertSortedDque(std::deque<std::pair<int, int> > *doubleDeque);

	int  get_jacobsthalN(int n);
	std::vector<int> getVec();
	std::deque<int> getDque();


	class PmergeMeException : public std::exception
	{
	public:
		PmergeMeException(const std::string &message);
		virtual const char *what() const throw();
		virtual ~PmergeMeException() throw() {}

	private:
		std::string _message;
	};
};

template <typename T>
void printC(const T &container)
{
	if (container.size() > 0)
	{
		typedef typename T::value_type ValueType;
		std::cout << "| ";
		std::copy(container.begin(), container.end(), std::ostream_iterator<ValueType>(std::cout, " | "));
		std::cout << std::endl;
	}
};

class NotNumberException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return ("Error: All the values must be numbers");
	}
};

class NotPositiveException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return ("Error: All the values must be positive");
	}
};

class IntMaxException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return ("Error: All the values must be in the int range");
	}
};

class DuplicateException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return ("Error: All the values must be different");
	}
};

#endif