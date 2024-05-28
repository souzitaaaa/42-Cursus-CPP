#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{

private:
	std::string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &cpy);
	~ShrubberyCreationForm();

	void beSigned(const Bureaucrat *signer);
	void action();
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &cpy);


#endif