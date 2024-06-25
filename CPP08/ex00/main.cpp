#include "easyfind.hpp"

int main()
{
    std::cout << YELLOW << "------------------EASY FINDS------------------" << RESET << std::endl;
    {
        std::cout << GREEN << "[ Vector ]" << RESET << std::endl;
        int arr[] = {1, 2, 3, 4, 5};
        std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
        printC(vec);
        try
        {
            std::vector<int>::iterator it = easyfind(vec, 5);
            VECTOR_VAL_INDEX(*it, vec)
        }
        catch (const std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
    {
        std::cout << GREEN << "[ List (Double linked list) ]" << RESET << std::endl;
        int arr[] = {5, 4, 3, 2, 1};
        std::list<int> lst(arr, arr + sizeof(arr) / sizeof(int));
        printC(lst);
        try
        {
            std::list<int>::iterator it = easyfind(lst, 5);
            LIST_VAL_INDEX(*it, lst)
        }
        catch (const std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
    {
        std::cout << GREEN << "[ Vector not INT ]" << RESET << std::endl;
        char arr[] = {'a', 'b', 'c', 'd', 'e'};
        std::vector<char> vec(arr, arr + sizeof(arr) / sizeof(char));
        printC(vec);
        try
        {
            std::vector<char>::iterator it = easyfind(vec, 'c');
            VECTOR_VAL_INDEX(*it, vec)
        }
        catch (const std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}