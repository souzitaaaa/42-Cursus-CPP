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

void RPN::operationStack(int token)
{
    int temp, temp2;
    switch (token)
    {
    case '+':
        temp = this->_stack.top();
        this->_stack.pop();
        temp2 = this->_stack.top();
        this->_stack.pop();
        this->_stack.push(temp2 + temp);
        break;
    case '-':
        temp = this->_stack.top();
        this->_stack.pop();
        temp2 = this->_stack.top();
        this->_stack.pop();
        this->_stack.push(temp2 - temp);
        break;
    case '*':
        temp = this->_stack.top();
        this->_stack.pop();
        temp2 = this->_stack.top();
        this->_stack.pop();
        this->_stack.push(temp2 * temp);
        break;
    case '/':
        temp = this->_stack.top();
        this->_stack.pop();
        temp2 = this->_stack.top();
        this->_stack.pop();
        this->_stack.push(temp2 / temp);
        break;
    }
}

void RPN::operation(int token)
{
    std::stack<int> tempStack;
    while (!this->_stack.empty())
    {
        tempStack.push(this->_stack.top());
        this->_stack.pop();
    }
    int temp;
    switch (token)
    {
    case '+':
        temp = tempStack.top();
        tempStack.pop();
        this->_stack.push(temp + tempStack.top());
        break;
    case '-':
        temp = tempStack.top();
        tempStack.pop();
        this->_stack.push(temp - tempStack.top());
        break;
    case '*':
        temp = tempStack.top();
        tempStack.pop();
        this->_stack.push(temp * tempStack.top());
        break;
    case '/':
        temp = tempStack.top();
        tempStack.pop();
        this->_stack.push(temp / tempStack.top());
        break;
    }
}

void RPN::calc(std::string equation)
{
    std::istringstream eq(equation);
    std::string token;
    while (std::getline(eq, token, ' '))
    {
        if (isdigit(token[0]))
        {
            int aux = std::atoi(token.c_str());
            this->_stack.push(aux);
            if (this->_stack.size() > 2)
            {
                if (std::getline(eq, token, ' '))
                    operationStack(token[0]);
                else
                    throw RPNException("Error: Invalid token in operation");
            }
        }
        else
        {
            if (isoperator(token[0]))
                operation(token[0]);
            else
                throw RPNException("Error: Invalid token in operation");
        }
    }
    printStack(this->_stack);
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