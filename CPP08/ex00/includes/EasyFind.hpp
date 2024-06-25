#ifndef EASYFIND_HPP
#define EASYFIND_HPP

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
#include <list>
#include <stack>
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\e[0;36m"
#define YELLOW "\e[0;33m"
#define BLACK "\033[0;30m"
#define RESET "\033[0m"
#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define VECTOR_VAL_INDEX(val, vec) std::cout << "Value " << val << " at [" << std::distance(vec.begin(), it) << "]" << std::endl;
#define LIST_VAL_INDEX(val, lst) std::cout << "Value " << val << " at [" << std::distance(lst.begin(), it) << "]" << std::endl;

class ValueNotFound : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return ("Value not Found");
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int val)
{
	typename T::iterator it = std::find(container.begin(), container.end(), val);
	if (it == container.end())
		throw ValueNotFound();
	return it;
};

template <typename T>
void printC(const T &container)
{
	// Creates an alias ValueType for the type of elements stored in T
	typedef typename T::value_type ValueType;
	// Use std::copy to iterate through the container and print each element
	std::cout << "| ";
	std::copy(container.begin(), container.end(), std::ostream_iterator<ValueType>(std::cout, " | "));
	std::cout << std::endl;
}

#endif