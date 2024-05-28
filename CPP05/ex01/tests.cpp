#include "Bureaucrat.hpp"
#include "Form.hpp"

//* BUREAUCRAT

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
            Bureaucrat b2;
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

//* FORM

void normal_init_form()
{
    {
        std::cout << "Normal Init:" << std::endl;
        try
        {
            Bureaucrat b1("Diogo", 150);
            std::cout << b1 << std::endl;
            Form f1("Form", 151, 50);
            std::cout << f1 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
        try
        {
            Bureaucrat b1("Rita", 1);
            std::cout << b1 << std::endl;
            Form f1("Form", 150, 0);
            std::cout << f1 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}

void operators_init_form()
{
    {
        std::cout << "\nOperators Init:" << std::endl;
        try
        {
            Form f1("Form1", 100, 100);
            std::cout << f1 << std::endl;
            Form f2 = f1;
            std::cout << f2 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
        try
        {
            Form f1("Form2", 100, 100);
            std::cout << f1 << std::endl;
            Form f2;
            f2 = f1;
            std::cout << f2 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}

void sign_form()
{
    {
        std::cout << "\nSigning Form:" << std::endl;
        try
        {
            Bureaucrat b1("Diogo", 101);
            std::cout << b1 << std::endl;
            Form f1("Form", 100, 50);
            std::cout << f1 << std::endl;
            f1.beSigned(&b1);
            std::cout << f1 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
        try
        {
            Bureaucrat b2("Diogo", 1);
            std::cout << b2 << std::endl;
            Form f2("Form", 100, 50);
            std::cout << f2 << std::endl;
            f2.beSigned(&b2);
            std::cout << f2 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}
