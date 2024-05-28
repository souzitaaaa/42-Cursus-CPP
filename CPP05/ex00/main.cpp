#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &out, const Bureaucrat &cpy)
{
    out << cpy.getName() << ", bureaucrat grade: " << cpy.getGrade();
    return out;
}

int main()
{
    normal_init();
    operators_init();
    setting_grade();
    increasing_grade();
    decreasing_grade();
}