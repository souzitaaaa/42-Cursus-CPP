#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Form"),
			   _signed(false),
			   _signGrade(150),
			   _execGrade(150)
{
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name),
															 _signed(false),
															 _signGrade(signGrade),
															 _execGrade(execGrade)
{
	std::cout << YELLOW << "Name constructor called" << RESET << std::endl;
	if (signGrade > 150)
		throw(Form::GradeTooLowException());
	else if (signGrade <= 0)
		throw(Form::GradeTooHighException());
	if (execGrade > 150)
		throw(Form::GradeTooLowException());
	else if (execGrade <= 0)
		throw(Form::GradeTooHighException());
}

Form::Form(const Form &cpy) : _name(cpy._name),
							  _signed(cpy._signed),
							  _signGrade(cpy._signGrade),
							  _execGrade(cpy._execGrade)
{
	std::cout << YELLOW << "Copy Form constructor called" << RESET << std::endl;
}

Form &Form::operator=(const Form &cpy)
{
	std::cout << "Copy operator called" << std::endl;
	if (this == &cpy)
		return *this;
	(this->_signed) = cpy._signed;
	return *this;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("❌ To high of a grade to assign in Form");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("❌ To low of a grade to assign in Form");
}

const char *Form::GradeTooLowSignException::what() const throw()
{
	return ("the grade is to LOW");
}

const char *Form::GradeSignedException::what() const throw()
{
	return ("the form is already SIGNED");
}

int Form::getSignGrade() const
{
	return (this->_signGrade);
}

int Form::getExecGrade() const
{
	return (this->_execGrade);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

void Form::setSigned(bool newVal)
{
	this->_signed = newVal;
}

std::string Form::getName() const
{
	return (this->_name);
}

void Form::beSigned(const Bureaucrat *signer)
{
	try
	{
		if (signer->getGrade() > this->getSignGrade())
			throw(Form::GradeTooLowSignException());
		if (this->getSigned())
			throw(Form::GradeSignedException());
		signer->signForm(this->getName());
		this->setSigned(true);
	}
	catch (std::exception &e)
	{
		std::cout << RED << signer->getName() << " couldn't sign ";
		std::cout << this->getName() << " because " << e.what() << RESET << std::endl;
	}
}

Form::~Form()
{
	std::cout << BLACK << "Destructor called" << RESET << std::endl;
}