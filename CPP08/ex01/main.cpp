#include "Span.hpp"

std::ostream &operator<<(std::ostream &out, const Span &base)
{
    out << "Span MaxN: " << base.getMaxN() << " && Vec Size: " << base.getVec().size() << std::endl;
    printC(base.getVec());
    return out;
}

int main()
{
    srand(time(NULL));
    std::cout << YELLOW << "------------------SPAN------------------" << RESET << std::endl;
    std::cout << CYAN << "[ Operators ]" << RESET << std::endl;
    {
        Span a;
        Span b(10);
        Span c(b);
        Span d;
        d = c;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
        std::cout << d << std::endl;
    }
    std::cout << CYAN << "[ Add Number ]" << RESET << std::endl;
    {
        Span a(2);
        std::cout << a << std::endl;
        try
        {
            a.addNumber(1);
            std::cout << a << std::endl;
            a.addNumber(2);
            std::cout << a << std::endl;
            a.addNumber(3);
            std::cout << a << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << a << std::endl;
    }
    std::cout << CYAN << "[ Shortest and Longests Span ]" << RESET << std::endl;
    {
        Span a(50);
        std::cout << a << std::endl;
        for (int i = 0; i < 50; i++)
        {
            a.addNumber(rand() % 10000);
        }
        std::cout << "ShortestSpan: " << a.shortestSpan() << std::endl;
        std::cout << "LongestSpan: " << a.longestSpan() << std::endl;
    }
    std::cout << CYAN << "[ Add Number by Iterator ]" << RESET << std::endl;
    {
        int arr[] = {2, 3, 4};
        std::vector<int> vec;
        vec.assign(arr, arr + sizeof(arr) / sizeof(int));
        Span a = Span(5);
        a.addNumber(1);
        std::cout << a << std::endl;
        a.addNumber(vec.begin(), vec.end());
        std::cout << a << std::endl;
    }
    std::cout << CYAN << "[ Subject ]" << RESET << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
}