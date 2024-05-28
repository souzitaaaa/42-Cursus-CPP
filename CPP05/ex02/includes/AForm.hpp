#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{

private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;

public:
	AForm();
	AForm(std::string name, int signGrade, int execGrade);
	AForm(const AForm &cpy);
	AForm &operator=(const AForm &cpy);
	virtual ~AForm();

	int getSignGrade() const;
	int getExecGrade() const;
	bool getSigned() const;
	std::string getName() const;
	virtual void beSigned(const Bureaucrat *signer) = 0;
	virtual void action() = 0;
	void execute(const Bureaucrat &executor) const;
	void setSigned(bool newVal);
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooLowSignException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class NotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &cpy);

#endif