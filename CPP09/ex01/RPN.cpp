#include "RPN.hpp"

RPN::RPN()
{
    std::cout << BLACK << "| Def. C |" << RESET << std::endl;
}

RPN::RPN(const RPN &cpy)
{
    (void)cpy;
    std::cout << BLACK << "| Copy C |" << RESET << std::endl;
}

RPN &RPN::operator=(const RPN &cpy)
{
    std::cout << BLACK << "| Assign. O |" << RESET << std::endl;
    if (this == &cpy)
        return *this;
    return *this;
}

bool RPN::isoperator(int token)
{
    if (token == '*' || token == '+' || token == '-' || token == '/')
        return true;
    return false;
}

void RPN::operation(int token)
{
    float second = this->_stack.top();
    this->_stack.pop();
    float first = this->_stack.top();
    this->_stack.pop();
    switch (token)
    {
    case '+':
        this->_result = first + second;
        this->_stack.push(this->_result);
        break;
    case '-':
        this->_result = first - second;
        this->_stack.push(this->_result);
        break;
    case '*':
        this->_result = first * second;
        this->_stack.push(this->_result);
        break;
    case '/':
        second == 0
            ? throw RPNException("Error: Can't do division by zero")
            : this->_result = first / second;
        this->_stack.push(this->_result);
        break;
    default:
        throw RPNException("Error: Unexpected Error");
    }
}

void RPN::init_queue(std::string equation)
{
    std::istringstream eq(equation);
    std::string token;
    while (std::getline(eq, token, ' '))
    {
        if (token.length() > 1)
            throw RPNException("Error: Expression may only include digits and valid operators");
        if (isdigit(token[0]))
            this->_queue.push(std::atoi(token.c_str()));
        else if (isoperator(token[0]))
            this->_queue.push(token[0]);
        else
            throw RPNException("Error: Expression may only include digits and valid operators");
    }
}

void RPN::calc(std::string equation)
{
    init_queue(equation);
    if (this->_queue.size() < 3)
        throw RPNException("Error: Expression must have at least 3 arguments");
    for (int i = 0; i < 2; i++)
    {
        if (this->_queue.front() > 10)
            throw RPNException("Error: The first two elements of the expression must be digits");
        else
            this->_stack.push(this->_queue.front());
        this->_queue.pop();
    }
    while (!this->_queue.empty())
    {
        if (this->_queue.front() < 10)
            this->_stack.push(this->_queue.front());
        else
            this->_stack.empty()
                ? throw RPNException("Error: Invalid expression")
                : operation(this->_queue.front());
        this->_queue.pop();
    }
    this->_stack.size() > 1
        ? throw RPNException("Error: Expression needs more operators")
        : std::cout << "[ " << this->_result << " ]" << std::endl;
}

RPN::RPNException::RPNException(const std::string &message) : _message(message) {}

const char *RPN::RPNException::what() const throw()
{
    return _message.c_str();
}

RPN::~RPN()
{
    std::cout << BLACK << "| Dest. |" << RESET << std::endl;
}