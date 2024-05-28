#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << YELLOW << "Default Intern constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern &cpy)
{
    *this = cpy;
    std::cout << YELLOW << "Copy Intern constructor called" << RESET << std::endl;
}

Intern &Intern::operator=(const Intern &cpy)
{
    std::cout << "Copy operator Intern called" << std::endl;
    if (this == &cpy)
        return *this;
    return *this;
}

const char *Intern::InvalidForm::what() const throw()
{
    return ("❌ Invalid Form");
}

AForm *Intern::makeForm(std::string fType, std::string fTarget)
{
    std::string typeoptions[3] = {"shrubbery", "robotomy", "presidential"};
    AForm *(Intern::*f[3])(std::string) = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential};
    AForm *out = 0;
    for (int i = 0; i < 3; i++)
    {
        if (!fType.compare(typeoptions[i]))
        {
            std::cout << GREEN << "Intern creates " << fType << RESET << std::endl;
            out = (this->*f[i])(fTarget);
            return out;
        }
    }
    throw(Intern::InvalidForm());
    return out;
}

AForm *Intern::createShrubbery(std::string fTarget)
{
    return new ShrubberyCreationForm(fTarget);
}

AForm *Intern::createRobotomy(std::string fTarget)
{
    return new RobotomyRequestForm(fTarget);
}

AForm *Intern::createPresidential(std::string fTarget)
{
    return new PresidentialPardonForm(fTarget);
}

Intern::~Intern()
{
    // std::cout << CYAN << "Destructor Intern called" << RESET << std::endl;
}