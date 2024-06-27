#ifndef ARRAY_HPP
#define ARRAY_HPP

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
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\e[0;36m"
#define YELLOW "\e[0;33m"
#define BLACK "\033[0;30m"
#define RESET "\033[0m"
#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

template <typename T>
class Array
{
private:
	T *_arr;
	unsigned int _arrSize;

public:
	Array() : _arr(new T[0]), _arrSize(0)
	{
		std::cout << BLACK << "| Def. C |" << RESET << std::endl;
	}
	Array(unsigned int n) : _arr(new T[n]), _arrSize(n)
	{
		std::cout << BLACK << "| Param. C |" << RESET << std::endl;
	}
	Array(const Array &cpy) : _arr(new T[cpy._arrSize]), _arrSize(cpy._arrSize)
	{
		std::cout << BLACK << "| Copy C |" << RESET << std::endl;
		for (unsigned int i = 0; i < cpy._arrSize; i++)
		{
			this->_arr[i] = cpy._arr[i];
		}
	}
	~Array()
	{
		std::cout << BLACK << "| D |" << RESET << std::endl;
		delete[] this->_arr;
	}
	Array &operator=(const Array &cpy)
	{
		std::cout << BLACK << "| Assign. O |" << RESET << std::endl;
		if (this == &cpy)
			return *this;
		if (this->_arr)
			delete[] this->_arr;
		this->_arr = new T[cpy._arrSize];
		this->_arrSize = cpy._arrSize;
		for (unsigned int i = 0; i < cpy._arrSize; i++)
		{
			this->_arr[i] = cpy._arr[i];
		}
		return *this;
	}
	T &operator[](unsigned int i)
	{
		if (i >= this->_arrSize)
			throw IndexOutBonds();
		return (this->_arr[i]);
	}
	const T &operator[](unsigned int i) const
	{
		if (i >= this->_arrSize)
			throw IndexOutBonds();
		return (this->_arr[i]);
	}
	unsigned int size()
	{
		return this->_arrSize;
	}
	class IndexOutBonds : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Index out of bonds");
		}
	};
};

#endif