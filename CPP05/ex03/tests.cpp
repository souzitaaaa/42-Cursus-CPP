#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

//* SHRUBBERY

void normal_init_shrubbery()
{
    {
        std::cout << "Normal Init:" << std::endl;
        try
        {
            ShrubberyCreationForm f1;
            std::cout << f1 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
        try
        {
            ShrubberyCreationForm f1("Home");
            std::cout << f1 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}

void operators_init_shrubbery()
{
    {
        std::cout << "\nOperators Init:" << std::endl;
        try
        {
            ShrubberyCreationForm f1("Home");
            std::cout << f1 << std::endl;
            ShrubberyCreationForm f2 = f1;
            std::cout << f2 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
        try
        {
            ShrubberyCreationForm f1("Home");
            std::cout << f1 << std::endl;
            ShrubberyCreationForm f2;
            f2 = f1;
            std::cout << f2 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}

void sign_shrubbery()
{
    {
        std::cout << "\nExec Form:" << std::endl;
        try
        {
            Bureaucrat b1("Diogo", 144);
            std::cout << b1 << std::endl;
            ShrubberyCreationForm f1("Home");
            std::cout << f1 << std::endl;
            b1.signForm(f1);
            std::cout << f1 << std::endl;
            b1.executeForm(f1);
            b1.setGrade(100);
            std::cout << b1 << std::endl;
            b1.executeForm(f1);
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
        try
        {
            Bureaucrat b1("Diogo", 144);
            std::cout << b1 << std::endl;
            ShrubberyCreationForm f1("Home");
            std::cout << f1 << std::endl;
            b1.executeForm(f1);
            b1.signForm(f1);
            std::cout << f1 << std::endl;
            b1.executeForm(f1);
            b1.setGrade(100);
            std::cout << b1 << std::endl;
            b1.executeForm(f1);
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}

//* ROBOTOMY

void normal_init_robotomy()
{
    {
        std::cout << "Normal Init:" << std::endl;
        try
        {
            RobotomyRequestForm f1;
            std::cout << f1 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
        try
        {
            RobotomyRequestForm f1("Home");
            std::cout << f1 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}

void operators_init_robotomy()
{
    {
        std::cout << "\nOperators Init:" << std::endl;
        try
        {
            RobotomyRequestForm f1("Home");
            std::cout << f1 << std::endl;
            RobotomyRequestForm f2 = f1;
            std::cout << f2 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
        try
        {
            RobotomyRequestForm f1("Home");
            std::cout << f1 << std::endl;
            RobotomyRequestForm f2;
            f2 = f1;
            std::cout << f2 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}

void sign_robotomy()
{
    {
        std::cout << "\nExec Form:" << std::endl;
        try
        {
            Bureaucrat b1("Diogo", 80);
            std::cout << b1 << std::endl;
            RobotomyRequestForm f1("Home");
            std::cout << f1 << std::endl;
            b1.signForm(f1);
            std::cout << f1 << std::endl;
            b1.setGrade(50);
            std::cout << b1 << std::endl;
            b1.signForm(f1);
            std::cout << f1 << std::endl;
            b1.executeForm(f1);
            b1.setGrade(30);
            std::cout << b1 << std::endl;
            b1.executeForm(f1);
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
        try
        {
            Bureaucrat b2("Diogo", 1);
            std::cout << b2 << std::endl;
            RobotomyRequestForm f2("Home");
            std::cout << f2 << std::endl;
            b2.executeForm(f2);
            b2.signForm(f2);
            std::cout << f2 << std::endl;
            b2.executeForm(f2);
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}

//* PRESIDENTIAL

void normal_init_presidential()
{
    {
        std::cout << "Normal Init:" << std::endl;
        try
        {
            PresidentialPardonForm f1;
            std::cout << f1 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
        try
        {
            PresidentialPardonForm f1("Diogo");
            std::cout << f1 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}

void operators_init_presidential()
{
    {
        std::cout << "\nOperators Init:" << std::endl;
        try
        {
            PresidentialPardonForm f1("Diogo");
            std::cout << f1 << std::endl;
            PresidentialPardonForm f2 = f1;
            std::cout << f2 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
        try
        {
            PresidentialPardonForm f1("Diogo");
            std::cout << f1 << std::endl;
            PresidentialPardonForm f2;
            f2 = f1;
            std::cout << f2 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}

void sign_presidential()
{
    {
        std::cout << "\nExec Form:" << std::endl;
        try
        {
            Bureaucrat b1("Rita", 80);
            std::cout << b1 << std::endl;
            PresidentialPardonForm f1("Xico");
            std::cout << f1 << std::endl;
            b1.signForm(f1);
            std::cout << f1 << std::endl;
            b1.setGrade(25);
            std::cout << b1 << std::endl;
            b1.signForm(f1);
            std::cout << f1 << std::endl;
            b1.executeForm(f1);
            b1.setGrade(2);
            std::cout << b1 << std::endl;
            b1.executeForm(f1);
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
        try
        {
            Bureaucrat b2("Jenny", 1);
            std::cout << b2 << std::endl;
            PresidentialPardonForm f2("Diogo");
            std::cout << f2 << std::endl;
            b2.executeForm(f2);
            b2.signForm(f2);
            std::cout << f2 << std::endl;
            b2.executeForm(f2);
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}

//* INTERN

void normal_init_intern()
{
    {
        std::cout << "Normal Init:" << std::endl;
        try
        {
            Intern i1;
            std::cout << i1 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}

void operators_init_intern()
{
    {
        std::cout << "\nOperators Init:" << std::endl;
        try
        {
            Intern i1;
            std::cout << &i1 << std::endl;
            Intern i2 = i1;
            std::cout << &i2 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
        try
        {
            Intern i1;
            std::cout << &i1 << std::endl;
            Intern i2;
            i2 = i1;
            std::cout << &i2 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}

void create_forms()
{
    {
        std::cout << "\nCreating Forms:" << std::endl;
        try
        {
            Intern i1;
            AForm *f1;
            AForm *f2;
            AForm *f3;
            std::cout << i1 << std::endl;
            f1 = i1.makeForm("shrubbery", "home");
            std::cout << *f1 << std::endl;
            f2 = i1.makeForm("robotomy", "jegger");
            std::cout << *f2 << std::endl;
            f3 = i1.makeForm("presidential", "bruno");
            std::cout << *f3 << std::endl;
            Bureaucrat b1("Diogo", 1);
            std::cout << b1 << std::endl;
            b1.signForm(*f2);
            b1.executeForm(*f2);
            b1.executeForm(*f1);
            delete f1;
            delete f2;
            delete f3;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
        AForm *f1 = 0;
        AForm *f2 = 0;
        try
        {
            Intern i1;

            f1 = i1.makeForm("shrubbery", "home");
            std::cout << *f1 << std::endl;
            f2 = i1.makeForm("aaaa", "jegger");
            std::cout << *f2 << std::endl;
            if (f1 != 0)
                delete f1;
            if (f2 != 0)
                delete f2;
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
            if (f1 != 0)
                delete f1;
            if (f2 != 0)
                delete f2;
        }
    }
}
