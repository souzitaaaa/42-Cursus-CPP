#ifndef RPN_HPP
#define RPN_HPP

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
#include <sstream>
#include <limits.h>
#include <float.h>
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\e[0;36m"
#define YELLOW "\e[0;33m"
#define BLACK "\033[0;30m"
#define RESET "\033[0m"
#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define WRONG_ARGS "Error: Please try ./RPN [equation]"

class RPN
{
private:
    std::stack<int> _stack;

public:
	RPN();
	RPN(const RPN &cpy);
	~RPN();
	RPN &operator=(const RPN &cpy);
	
	void calc(std::string equation);
	bool isoperator(int token);
	void operation(int token);

	class RPNException : public std::exception
	{
	public:
		RPNException(const std::string &message);
		virtual const char *what() const throw();
		virtual ~RPNException() throw() {}

	private:
		std::string _message;
	};
};

template <typename T>
void printStack(std::stack<T> stack)
{
	std::stack<T> tempStack;
	std::stack<T> reverseStack;

	while (!stack.empty())
	{
		reverseStack.push(stack.top());
		stack.pop();
	}
	while (!reverseStack.empty())
	{
		tempStack.push(reverseStack.top());
		reverseStack.pop();
	}
	while (!tempStack.empty())
	{
		std::cout << "| " << tempStack.top() << " | ";
		tempStack.pop();
	}
	std::cout << std::endl;
}

#endif