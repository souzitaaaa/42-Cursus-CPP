#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

std::ostream &operator<<(std::ostream &out, const Bureaucrat &cpy)
{
    out << cpy.getName() << ", bureaucrat grade: " << cpy.getGrade();
    return out;
}

std::ostream &operator<<(std::ostream &out, const AForm &cpy)
{
    out << "AForm: " << cpy.getName() << " | Signed -> " << (cpy.getSigned() == 0 ? "false" : "true") << ", SignGrade -> " << cpy.getSignGrade() << ", ExecGrade -> " << cpy.getExecGrade();
    return out;
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &cpy)
{
    out << "ShrubberyCreationForm: " << cpy.getName() << " | Signed -> " << (cpy.getSigned() == 0 ? "false" : "true") << ", SignGrade -> " << cpy.getSignGrade() << ", ExecGrade -> " << cpy.getExecGrade();
    return out;
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &cpy)
{
    out << "RobotomyRequestForm: " << cpy.getName() << " | Signed -> " << (cpy.getSigned() == 0 ? "false" : "true") << ", SignGrade -> " << cpy.getSignGrade() << ", ExecGrade -> " << cpy.getExecGrade();
    return out;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &cpy)
{
    out << "PresidentialPardonForm: " << cpy.getName() << " | Signed -> " << (cpy.getSigned() == 0 ? "false" : "true") << ", SignGrade -> " << cpy.getSignGrade() << ", ExecGrade -> " << cpy.getExecGrade();
    return out;
}

void continue_tests()
{
    std::cout << "\nPress Enter to Continue...\n";
    std::cin.ignore();
    if (std::cin.eof())
        exit(0);
    std::system("clear");
}

int main()
{
    srand(time(NULL));
    std::cout << "BUREAUCRAT TESTES:.\n"
              << std::endl;
    normal_init();
    operators_init();
    setting_grade();
    increasing_grade();
    decreasing_grade();
    continue_tests();
    std::cout << "SHRUBBERY FORM TESTS:.\n"
              << std::endl;
    normal_init_shrubbery();
    operators_init_shrubbery();
    sign_shrubbery();
    continue_tests();
    std::cout << "ROBOTOMY FORM TESTS:.\n"
              << std::endl;
    normal_init_robotomy();
    operators_init_robotomy();
    sign_robotomy();
    continue_tests();
    std::cout << "PRESIDENTIAL FORM TESTS:.\n"
              << std::endl;
    normal_init_presidential();
    operators_init_presidential();
    sign_presidential();
}