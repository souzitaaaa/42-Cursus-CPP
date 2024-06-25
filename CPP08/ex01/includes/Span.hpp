#ifndef SPAN_HPP
#define SPAN_HPP

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
#include <vector>
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\e[0;36m"
#define YELLOW "\e[0;33m"
#define BLACK "\033[0;30m"
#define RESET "\033[0m"
#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

class Span
{
private:
	unsigned int _maxN;
	std::vector<int> _vec;

public:
	Span();
	Span(unsigned int maxN);
	Span(const Span &cpy);
	~Span();
	Span &operator=(const Span &cpy);

	unsigned int getMaxN() const;
	std::vector<int> getVec() const;
	std::vector<int> getVec();
	void addNumber(int val);
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan();
	int longestSpan();

	class ContainerMax : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Container max reached");
		}
	};
	class NoSpanFound : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("No Span found");
		}
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
}

#endif