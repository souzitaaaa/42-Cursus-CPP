#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << YELLOW << "Name constructor called" << RESET << std::endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy._name),
												_grade(cpy._grade)
{
	std::cout << YELLOW << "Copy Buconstructor called" << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpy)
{
	std::cout << "Copy operator called" << std::endl;
	if (this == &cpy)
		return *this;
	this->_grade = cpy._grade;
	return *this;
}

void Bureaucrat::increaseGrade()
{
	this->setGrade(this->getGrade() - 1);
}

void Bureaucrat::decreaseGrade()
{
	this->setGrade(this->getGrade() + 1);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("❌ To high of a grade to assign");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("❌ To low of a grade to assign");
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::setGrade(int newGrade)
{
	if (newGrade > 150)
		throw(Bureaucrat::GradeTooLowException());
	else if (newGrade <= 0)
		throw(Bureaucrat::GradeTooHighException());
	this->_grade = newGrade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << BLACK << "Destructor called" << RESET << std::endl;
}