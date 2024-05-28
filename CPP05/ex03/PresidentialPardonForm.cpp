#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << YELLOW << "Default PPF constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5),
																	 _target(target)
{
	std::cout << YELLOW << "Name PPF constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm(cpy),
																					_target(cpy._target)
{
	std::cout << YELLOW << "Copy PPF constructor called" << RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &cpy)
{
	std::cout << "Copy operator PPF called" << std::endl;
	if (this == &cpy)
		return *this;
	this->_target = cpy._target;
	this->setSigned(cpy.getSigned());
	return *this;
}

void PresidentialPardonForm::beSigned(const Bureaucrat *signer)
{
	if (signer->getGrade() > this->getSignGrade())
		throw(AForm::GradeTooLowSignException());
	if (this->getSigned())
		throw(AForm::GradeSignedException());
	this->setSigned(true);
}

void PresidentialPardonForm::action()
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << CYAN << "Destructor PPF called" << RESET << std::endl;
}