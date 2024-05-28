#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern
{

private:
public:
    Intern();
    Intern(const Intern &cpy);
    Intern &operator=(const Intern &cpy);
    ~Intern();

    AForm *makeForm(std::string fType, std::string fTarget);
    AForm *createShrubbery(std::string fTarget);
    AForm *createRobotomy(std::string fTarget);
    AForm *createPresidential(std::string fTarget);
    class InvalidForm : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Intern &cpy);

#endif