#include "Bureaucrat.hpp"

void normal_init()
{
    {
        std::cout << "Normal Init:" << std::endl;
        try
        {
            Bureaucrat b1("Diogo", 151);
            std::cout << b1 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
        try
        {
            Bureaucrat b1("Rita", 0);
            std::cout << b1 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}

void operators_init()
{
    {
        std::cout << "\nOperators Init:" << std::endl;
        try
        {
            Bureaucrat b1("Jegger", 150);
            std::cout << b1 << std::endl;
            Bureaucrat b2 = b1;
            std::cout << b2 << std::endl;
            b2.setGrade(1);
            std::cout << b2 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
        try
        {
            Bureaucrat b1("Bruno", 1);
            std::cout << b1 << std::endl;
            Bureaucrat b2("Idk", 100);
            std::cout << b2 << std::endl;
            b2 = b1;
            std::cout << b2 << std::endl;
            b2.setGrade(150);
            std::cout << b2 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}

void setting_grade()
{
    {
        std::cout << "\nSetting Grade:" << std::endl;
        try
        {
            Bureaucrat b1("Diogo", 150);
            std::cout << b1 << std::endl;
            b1.setGrade(1);
            std::cout << b1 << std::endl;
            b1.setGrade(0);
            std::cout << b1 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
        try
        {
            Bureaucrat b1("Rita", 150);
            std::cout << b1 << std::endl;
            b1.setGrade(1);
            std::cout << b1 << std::endl;
            b1.setGrade(151);
            std::cout << b1 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}

void increasing_grade()
{
    {
        std::cout << "\nIncreasing Grade:" << std::endl;
        try
        {
            Bureaucrat b1("Jenny", 2);
            std::cout << b1 << std::endl;
            b1.increaseGrade();
            std::cout << b1 << std::endl;
            b1.increaseGrade();
            std::cout << b1 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}

void decreasing_grade()
{
    {
        std::cout << "\nDecreasing Grade:" << std::endl;
        try
        {
            Bureaucrat b1("Xico", 149);
            std::cout << b1 << std::endl;
            b1.decreaseGrade();
            std::cout << b1 << std::endl;
            b1.decreaseGrade();
            std::cout << b1 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}
