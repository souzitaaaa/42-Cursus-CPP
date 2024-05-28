#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

private:
	std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &cpy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &cpy);
	~PresidentialPardonForm();

	void beSigned(const Bureaucrat *signer);
	void action();
};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &cpy);

#endif