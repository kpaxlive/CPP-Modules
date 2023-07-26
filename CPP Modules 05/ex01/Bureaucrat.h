#pragma once

#include <iostream>
#include "Form.h"

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
		void setGrade(int _grade);
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int _grade);
		Bureaucrat(const Bureaucrat& var);
		~Bureaucrat();
		
		Bureaucrat& operator=(const Bureaucrat& var);

		std::string getName() const;
		int getGrade() const;
		void increment_grade();
		void decrement_grade();

		void signForm(Form &var);

	class GradeTooHighException :public std::exception
	{
		public:
			const char *what() const throw();
	};
	class GradeTooLowException:public std::exception
	{
		public:
			const char	*what() const throw();
	};
};

std::ostream &operator<<(std::ostream &OUT , const Bureaucrat& var);
