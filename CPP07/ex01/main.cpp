#include "iter.hpp"

int main()
{
    std::cout << YELLOW << "------------------ITER------------------" << RESET << std::endl;
    {
        std::string arr[] = {"Diogo", "Rita", "Jenny", "Xico", "Jegger", "Bruno",};
        ::iter(arr, ARR_SIZE(arr), print<std::string>);
        std::cout << "\nWith const: " << std::endl;
        ::iter(arr, ARR_SIZE(arr), print<const std::string>);
    }
}