#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << YELLOW << "Default RRF constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45),
															   _target(target)
{
	std::cout << YELLOW << "Name RRF constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy),
																		   _target(cpy._target)
{
	std::cout << YELLOW << "Copy RRF constructor called" << RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy)
{
	std::cout << "Copy operator RRF called" << std::endl;
	if (this == &cpy)
		return *this;
	this->_target = cpy._target;
	this->setSigned(cpy.getSigned());
	return *this;
}

void RobotomyRequestForm::beSigned(const Bureaucrat *signer)
{

	if (signer->getGrade() > this->getSignGrade())
		throw(AForm::GradeTooLowSignException());
	if (this->getSigned())
		throw(AForm::GradeSignedException());
	this->setSigned(true);
}

void RobotomyRequestForm::action()
{
	std::cout << "🔩 https://www.youtube.com/watch?v=e839iBeupx4 🔩" << std::endl;
	int randNum = (rand() % 2) + 1;
	randNum == 1 ? std::cout << this->_target << " was ROBOTOMIZED (tf is that supposed to mean)" << std::endl
				 : std::cout << this->_target << " was not ROBOTOMIZED (that must be safer)" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << CYAN << "Destructor RRF called" << RESET << std::endl;
}