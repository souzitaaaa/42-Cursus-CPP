#include "Template.hpp"

int main()
{
    std::cout << YELLOW << "------------------SWAP------------------" << RESET << std::endl;
    {
        int a = 1;
        int b = 3;
        std::cout << "INTEGERS:" << std::endl;
        std::cout << GREEN << "a: " << a << " | " << "b: " << b << RESET << std::endl;
        ::swap(a, b);
        std::cout << GREEN << "a: " << a << " | " << "b: " << b << RESET << std::endl;
        float c = 1.2f;
        float d = 3.1f;
        std::cout << "FLOATS:" << std::endl;
        std::cout << GREEN << "c: " << c << " | " << "d: " << d << RESET << std::endl;
        ::swap(c, d);
        std::cout << GREEN << "c: " << c << " | " << "d: " << d << RESET << std::endl;
        std::string e = "Lua";
        std::string f = "Estrela";
        std::cout << "STRING:" << std::endl;
        std::cout << GREEN << "e: " << e << " | " << "f: " << f << RESET << std::endl;
        ::swap(e, f);
        std::cout << GREEN << "e: " << e << " | " << "f: " << f << RESET << std::endl;
    }
    std::cout << YELLOW << "------------------MIN-------------------" << RESET << std::endl;
    {
        int a = 1;
        int b = 3;
        std::cout << "INTEGERS:" << std::endl;
        std::cout << GREEN << "a: " << a << " | " << "b: " << b << " | min: " << ::min(a, b) << RESET << std::endl;
        float c = 1.2f;
        float d = 3.1f;
        std::cout << "FLOATS:" << std::endl;
        std::cout << GREEN << "c: " << c << " | " << "d: " << d << " | min: " << ::min(c, d) << RESET << std::endl;
        std::string e = "A";
        std::string f = "B";
        std::cout << "STRING:" << std::endl;
        std::cout << GREEN << "e: " << e << " | " << "f: " << f << " | min: " << ::min(e, f) << RESET << std::endl;
    }
    std::cout << YELLOW << "------------------MAX-------------------" << RESET << std::endl;
    {
        int a = 1;
        int b = 3;
        std::cout << "INTEGERS:" << std::endl;
        std::cout << GREEN << "a: " << a << " | " << "b: " << b << " | max: " << ::max(a, b) << RESET << std::endl;
        float c = 1.2f;
        float d = 3.1f;
        std::cout << "FLOATS:" << std::endl;
        std::cout << GREEN << "c: " << c << " | " << "d: " << d << " | max: " << ::max(c, d) << RESET << std::endl;
        std::string e = "A";
        std::string f = "B";
        std::cout << "STRING:" << std::endl;
        std::cout << GREEN << "e: " << e << " | " << "f: " << f << " | max: " << ::max(e, f) << RESET << std::endl;
    }
}