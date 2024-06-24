#include "array.hpp"

#define MAX_VAL 750

int main()
{
    std::cout << YELLOW << "------------------OWN ARRAY TESTS------------------" << RESET << std::endl;
    {
        Array<int> n_arr;
        Array<char> c_arr(3);
        Array<char> c_arr2(c_arr);
        Array<int> n_arr2;
        n_arr2 = n_arr;
        for (unsigned int i = 0; i < 3; i++)
        {
            c_arr[i] = 'a' + i;
        }
        for (unsigned int i = 0; i < 3; i++)
        {
            std::cout << c_arr[i] << std::endl;
        }
        try
        {
            for (unsigned int i = 0; i <= 3; i++)
            {
                c_arr2[i] = 'z' - i;
            }
        }
        catch (const std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
        for (unsigned int i = 0; i < 3; i++)
        {
            std::cout << c_arr2[i] << std::endl;
        }
    }
    std::cout << YELLOW << "------------------INTRA ARRAY TESTS------------------" << RESET << std::endl;
    {
        Array<int> numbers(MAX_VAL);
        int *mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        // SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete[] mirror; //
        return 0;
    }
}