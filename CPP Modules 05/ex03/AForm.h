#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.h"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool sign;
		const int req_grade;
		const int ex_grade;
	protected:
		bool ex;
	public:

		AForm();
		AForm(std::string, int, int);
		AForm(const AForm &);
		virtual ~AForm();
		AForm& operator=(const AForm &other);

		virtual std::string	getName() const;
		bool		getSign() const;
		bool		getEx() const;
		int			getReqGrade() const;
		int			getExGrade() const;
		void		beSigned(const Bureaucrat &var);
		
		virtual void	execute(Bureaucrat const & executor) = 0;
		
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
		class FormNotSignedException:public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out , const AForm& var);

#endif