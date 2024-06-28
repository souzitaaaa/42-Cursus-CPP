#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

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
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\e[0;36m"
#define YELLOW "\e[0;33m"
#define BLACK "\033[0;30m"
#define RESET "\033[0m"
#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
private:
public:
	MutantStack() : std::stack<T, C>()
	{
		std::cout << BLACK << "| Def. C |" << RESET << std::endl;
	};
	MutantStack(const MutantStack &cpy) : std::stack<T, C>(cpy)
	{
		std::cout << BLACK << "| Copy C |" << RESET << std::endl;
	};
	MutantStack &operator=(const MutantStack &cpy)
	{
		std::cout << BLACK << "| Assign O |" << RESET << std::endl;
		if (this == &cpy)
			return *this;
		std::stack<T, C>::operator=(cpy);
		return *this;
	}
	~MutantStack()
	{
		std::cout << BLACK << "| Dest. |" << RESET << std::endl;
	};
	// The c in c.begin() and c.end() is a container_type defined in the stack class
	typedef typename C::iterator iterator;
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	typedef typename C::const_iterator const_iterator;
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
	typedef typename C::reverse_iterator reverse_iterator;
	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }
	typedef typename C::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	const_reverse_iterator rend() const { return this->c.rend(); }
};

template <typename T>
void printStack(std::stack<T> stack)
{
	std::stack<T> reversedStack;
	std::stack<T> tempStack;

	while (!stack.empty())
	{
		reversedStack.push(stack.top());
		stack.pop();
	}
	while (!reversedStack.empty())
	{
		tempStack.push(reversedStack.top());
		reversedStack.pop();
	}
	while (!tempStack.empty())
	{
		std::cout << "| " << tempStack.top() << " | ";
		tempStack.pop();
	}
	std::cout << std::endl;
}

#endif