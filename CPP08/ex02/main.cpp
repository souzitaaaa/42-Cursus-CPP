#include "MutantStack.hpp"

template <typename T>
std::ostream &operator<<(std::ostream &out, const MutantStack<T> &base)
{
    out << "Stack: " << std::endl;
    printStack(base);
    return out;
}

int main()
{
    std::cout << YELLOW << "------------------STACK TESTS------------------" << RESET << std::endl;
    {
        std::stack<int> stack;

        stack.empty()
            ? std::cout << "Stack is empty" << std::endl
            : std::cout << "Stack is not empty" << std::endl;
        std::cout << CYAN << "Adding values to the stack" << RESET << std::endl;
        for (int i = 0; i < 5; i++)
        {
            stack.push(i);
        }
        stack.empty()
            ? std::cout << "Stack is empty" << std::endl
            : std::cout << "Stack is not empty" << std::endl;
        printStack(stack);
        std::cout << "First value on the stack: " << stack.top() << std::endl;
        std::cout << "Size of the stack: " << stack.size() << std::endl;
        stack.pop();
        std::cout << "First value on the stack after pop: " << stack.top() << std::endl;
        std::cout << "Size of the stack after pop: " << stack.size() << std::endl;
        printStack(stack);
    }
    std::cout << YELLOW << "------------------MUTANT STACK------------------" << RESET << std::endl;
    std::cout << CYAN << "[ Operators ]" << RESET << std::endl;
    {
        MutantStack<int> a;
        MutantStack<int> b(a);
        MutantStack<int> c;
        c = b;
        a.push(1);
        std::cout << a;
        std::cout << b;
        c.push(5);
        std::cout << c;
    }
    std::cout << CYAN << "[ Iterators ]" << RESET << std::endl;
    {
        MutantStack<int> a;
        a.push(1);
        a.push(2);
        std::cout << a;
        std::cout << "Top: " << a.top() << std::endl;
        a.pop();
        std::cout << a;
        std::cout << "Size after pop: " << a.size() << std::endl;
        a.push(2);
        a.push(3);
        std::cout << a;
        MutantStack<int>::iterator it = a.begin();
        std::cout << "Iterator Begin: " << *it << std::endl;
        MutantStack<int>::iterator ite = a.end();
        std::cout << "Iterator End:   " << *ite << std::endl;
        ++it;
        std::cout << "Iterator ++:    " << *ite << std::endl;
        --it;
        std::cout << "Iterator --:    " << *it << std::endl;
        while (it != ite)
        {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;
        for (MutantStack<int>::const_iterator cit = a.begin(); cit != a.end(); ++cit)
        {
            std::cout << *cit << " ";
        }
        std::cout << std::endl;
        for (MutantStack<int>::reverse_iterator rit = a.rbegin(); rit != a.rend(); ++rit)
        {
            std::cout << *rit << " ";
        }
        std::cout << std::endl;
        for (MutantStack<int>::const_reverse_iterator crit = a.rbegin(); crit != a.rend(); ++crit)
        {
            std::cout << *crit << " ";
        }
        std::cout << std::endl;
    }
}