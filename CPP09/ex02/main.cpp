#include "PmergeMe.hpp"

long long currTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000LL + tv.tv_usec;
}

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
    if (argc > 2)
    {
        std::cout << YELLOW << "------------------PMERGEME------------------" << RESET << std::endl;
        try
        {
            std::vector<int> arguments;
            check_input(&arguments, argc, argv);
            PmergeMe PmM(arguments);
            std::cout << YELLOW << "Unsorted: " << RESET;
            printC(arguments);
            long long begin = currTime();
            PmM.vecsort();
            long long end = currTime();
            std::cout << YELLOW << "Sorted with vector: " << RESET;
            printC(PmM.getVec());
            std::cout << "Time to process a range of " << YELLOW << argc - 1 << RESET << " elements with std::vector: ";
            std::cout << GREEN << static_cast<double>(end - begin) / 1000 << RESET << " ms\n";
            begin = currTime();
            PmM.dquesort();
            end = currTime();
            std::cout << YELLOW << "Sorted with deque:  " << RESET;
            printC(PmM.getDque());
            std::cout << "Time to process a range of " << YELLOW << argc - 1 << RESET << " elements with std::deque: ";
            std::cout << GREEN << static_cast<double>(end - begin) / 1000 << RESET << " ms\n";
        }
        catch (const std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
    else if (argc == 2)
    {
        try
        {
        std::vector<int> arguments;
        check_input(&arguments, argc, argv);
        PmergeMe PmM(arguments);
        std::cout << YELLOW << "Unsorted: " << RESET;
        printC(arguments);
        long long begin = currTime();
        long long end = currTime();
        std::cout << YELLOW << "Sorted with vector: " << RESET;
        printC(PmM.getVec());
        std::cout << "Time to process a range of " << YELLOW << argc - 1 << RESET << " elements with std::vector: ";
        std::cout << GREEN << static_cast<double>(end - begin) / 1000 << RESET << " ms\n";
        begin = currTime();
        end = currTime();
        std::cout << YELLOW << "Sorted with deque:  " << RESET;
        printC(PmM.getDque());
        std::cout << "Time to process a range of " << YELLOW << argc - 1 << RESET << " elements with std::deque: ";
        std::cout << GREEN << static_cast<double>(end - begin) / 1000 << RESET << " ms\n";
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