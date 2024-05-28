#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{

private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;

public:
	Form();
	Form(std::string name, int signGrade, int execGrade);
	Form(const Form &cpy);
	Form &operator=(const Form &cpy);
	~Form();

	int getSignGrade() const;
	int getExecGrade() const;
	bool getSigned() const;
	std::string getName() const;
	void beSigned(const Bureaucrat *signer);
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
};

std::ostream &operator<<(std::ostream &out, const Form &cpy);

#endif