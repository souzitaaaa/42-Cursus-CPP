#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\e[0;36m"
#define YELLOW "\e[0;33m"
#define BLACK "\033[0;30m"
#define RESET "\033[0m"

class Bureaucrat
{

private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &cpy);
	Bureaucrat &operator=(const Bureaucrat &cpy);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void increaseGrade();
	void decreaseGrade();
	void setGrade(int newGrade);
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
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &cpy);
void normal_init();
void setting_grade();
void increasing_grade();
void decreasing_grade();
void operators_init();

#endif