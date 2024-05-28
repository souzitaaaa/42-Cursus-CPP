#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{

private:
	std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &cpy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &cpy);
	~RobotomyRequestForm();

	void beSigned(const Bureaucrat *signer);
	void action();
};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &cpy);


#endif