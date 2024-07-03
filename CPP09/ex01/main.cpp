#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::cout << YELLOW << "------------------RPN------------------" << RESET << std::endl;
        RPN rpn;

        try
        {
            rpn.calc(argv[1]);
        }
        catch (const std::exception &e)
        {
            std::cout << RED << e.what() << std::endl;
        }
    }
    else
    {
        std::cout << RED << WRONG_ARGS << RESET << std::endl;
    }
}