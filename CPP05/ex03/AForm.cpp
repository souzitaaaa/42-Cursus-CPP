#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("AForm"),
				 _signed(false),
				 _signGrade(150),
				 _execGrade(150)
{
	std::cout << YELLOW << "Default AF constructor called" << RESET << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name),
															   _signed(false),
															   _signGrade(signGrade),
															   _execGrade(execGrade)
{
	std::cout << YELLOW << "Name constructor AF called" << RESET << std::endl;
	if (signGrade > 150)
		throw(AForm::GradeTooLowException());
	else if (signGrade <= 0)
		throw(AForm::GradeTooHighException());
	if (execGrade > 150)
		throw(AForm::GradeTooLowException());
	else if (execGrade <= 0)
		throw(AForm::GradeTooHighException());
}

AForm::AForm(const AForm &cpy) : _name(cpy._name),
								 _signed(cpy._signed),
								 _signGrade(cpy._signGrade),
								 _execGrade(cpy._execGrade)
{
	std::cout << YELLOW << "Copy AF constructor called" << RESET << std::endl;
}

AForm &AForm::operator=(const AForm &cpy)
{
	std::cout << "Copy operator AF called" << std::endl;
	if (this == &cpy)
		return *this;
	this->_signed = cpy._signed;
	return *this;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("❌ To high of a grade to assign in AForm");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("❌ To low of a grade to assign in AForm");
}

const char *AForm::GradeTooLowSignException::what() const throw()
{
	return ("the grade is to LOW");
}

const char *AForm::GradeSignedException::what() const throw()
{
	return ("the form is already SIGNED");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("the form is not SIGNED");
}

int AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int AForm::getExecGrade() const
{
	return (this->_execGrade);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

void AForm::setSigned(bool newVal)
{
	this->_signed = newVal;
}

std::string AForm::getName() const
{
	return (this->_name);
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowSignException());
	if (!this->getSigned())
		throw(AForm::NotSignedException());
}

AForm::~AForm()
{
	// std::cout << CYAN << "Destructor called" << RESET << std::endl;
}