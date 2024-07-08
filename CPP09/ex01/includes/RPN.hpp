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
#include <queue>
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
	float _result;
	std::queue<int> _queue;
	std::stack<float> _stack;

public:
	RPN();
	RPN(const RPN &cpy);
	~RPN();
	RPN &operator=(const RPN &cpy);

	void calc(std::string equation);
	void init_queue(std::string equation);
	bool isoperator(int token);
	void operation(int token);
	void operationStack(int token);

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
	std::stack<T> s = stack;
	while (!s.empty())
	{
		std::cout << "| " << s.top() << " |";
		s.pop();
	}
	std::cout << '\n';
}

template <typename T>
void printQueue(std::queue<T> queue)
{
	std::queue<T> q = queue;
	while (!q.empty())
	{
		std::cout << "| " << q.front() << " |";
		q.pop();
	}
	std::cout << '\n';
}

#endif