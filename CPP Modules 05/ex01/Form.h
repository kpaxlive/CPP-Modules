#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.h"
#include "Bureaucrat.h"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool sign;
		const int req_grade;
		const int ex_grade;
		
	public:

		Form();
		Form(std::string, int, int);
		Form(const Form &);
		~Form();
		Form& operator=(const Form &other);

		std::string	getName() const;
		bool			getSign() const;
		int			getReqGrade() const;
		int			getExGrade() const;
		void		beSigned(const Bureaucrat &var);

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

std::ostream &operator<<(std::ostream &out , const Form& var);

#endif