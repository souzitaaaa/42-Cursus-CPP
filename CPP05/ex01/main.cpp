#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream &operator<<(std::ostream &out, const Bureaucrat &cpy)
{
    out << cpy.getName() << ", bureaucrat grade: " << cpy.getGrade();
    return out;
}

std::ostream &operator<<(std::ostream &out, const Form &cpy)
{
    out << "Form: " << cpy.getName() << " | Signed -> " << (cpy.getSigned() == 0 ? "false" : "true") << ", SignGrade -> " << cpy.getSignGrade() << ", ExecGrade -> " << cpy.getExecGrade();
    return out;
}

int main()
{
    std::cout << "BUREAUCRAT TESTES:.\n"
              << std::endl;
    normal_init();
    operators_init();
    setting_grade();
    increasing_grade();
    decreasing_grade();
    std::cout << "\nPress Enter to Continue...\n";
    std::cin.ignore();
    if (std::cin.eof())
        exit(0);
    std::system("clear");
    std::cout << "FORM TESTS:.\n"
              << std::endl;
    normal_init_form();
    operators_init_form();
    sign_form();
}