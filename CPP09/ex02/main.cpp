#include "PmergeMe.hpp"

bool isNumber(std::string token)
{
    if (token.empty())
        return false;
    for (unsigned int i = 0; i < token.length(); i++)
    {
        if (i == 0)
        {
            if (token[i] == '-' || token[i] == '+')
                continue;
        }
        else if (isdigit(token[i]))
            continue;
        else
            return false;
    }
    return true;
}

void check_input(std::vector<int> *arguments, int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        if (!isNumber(argv[i]))
            throw NotNumberException();
        long number = std::atol(argv[i]);
        if (number < 1)
            throw NotPositiveException();
        if (number >= INT_MAX)
            throw IntMaxException();
        for (std::vector<int>::iterator it = arguments->begin(); it != arguments->end(); it++)
        {
            if (*it == number)
                throw DuplicateException();
        }
        arguments->push_back(std::atoi(argv[i]));
    }
}

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        std::cout << YELLOW << "------------------PMERGEME------------------" << RESET << std::endl;
        try
        {
            std::vector<int> arguments;
            check_input(&arguments, argc, argv);
            PmergeMe PmM(arguments);
            std::cout << YELLOW << "Before: " << RESET;
            printC(arguments);
            clock_t begin = clock();
            PmM.vecsort();
            clock_t end = clock();
            std::cout << "Time to process a range of " << YELLOW << argc - 1  << RESET << " elements with std::vector : ";
            std::cout << GREEN << ((static_cast<double>(end - begin) / CLOCKS_PER_SEC) * 1000) << RESET << " us\n";
        }
        catch (const std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
    else
    {
        std::cout << RED << WRONG_ARGS << RESET << std::endl;
    }
}