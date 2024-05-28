#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << YELLOW << "Default SCF constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137),
																   _target(target)
{
	std::cout << YELLOW << "Name SCF constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy),
																				 _target(cpy._target)
{
	std::cout << YELLOW << "Copy SCF constructor called" << RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy)
{
	std::cout << "Copy operator SCF called" << std::endl;
	if (this == &cpy)
		return *this;
	this->_target = cpy._target;
	this->setSigned(cpy.getSigned());
	return *this;
}

void ShrubberyCreationForm::beSigned(const Bureaucrat *signer)
{
	if (signer->getGrade() > this->getSignGrade())
		throw(AForm::GradeTooLowSignException());
	if (this->getSigned())
		throw(AForm::GradeSignedException());
	this->setSigned(true);
}

void ShrubberyCreationForm::action()
{
	std::string art =
		"                  %%%,%%%%%%%\n"
		"                   ,'%% \\-*%%%%%%%\n"
		"             ;%%%%%*%   _%%%%\"\n"
		"              ,%%%       \\(_.*%%%%.\n"
		"              % *%%, ,%%%%*(    '\n"
		"            %^     ,*%%% )\\|,%%*%,_\n"
		"                 *%    \\/ #).-\"*%%*\n"
		"                     _.) ,/ *%,\n"
		"             _________/)#(_____________\n";
	std::string fileName = this->_target.append("_shrubbery");
	std::ofstream fileCreated(fileName.c_str());
	if (fileCreated.is_open())
	{
		fileCreated << art;
		fileCreated.close();
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << CYAN << "Destructor SCF called" << RESET << std::endl;
}