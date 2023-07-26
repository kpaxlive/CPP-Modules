#include "Form.h"

Form::Form() : name("No Name"), req_grade(150), ex_grade(150)
{
	sign = false;
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(std::string _name, int reqGrade, int exGrade) : name(_name), req_grade(reqGrade), ex_grade(exGrade)
{
	if (this->req_grade < 1 || this->ex_grade < 1)
        throw Form::GradeTooHighException();
    if (this->req_grade > 150 || this->ex_grade > 150)
        throw  Form::GradeTooLowException();
	sign = false;
	std::cout << "Form name constructor called" << std::endl;
}

Form::Form(const Form &var) : name(var.getName()), req_grade(var.getReqGrade()), ex_grade(var.getExGrade())
{
	sign = var.getSign();
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form& Form::operator=(const Form &var)
{
	sign = var.getSign();
	std::cout << "Form assigment operator overload called" << std::endl;
	return (*this);
}

std::ostream &operator<<(std::ostream &out , const Form& var)
{
	out << "Form " << var.getName() << (var.getSign() ? " is signed!" : " not signed!");
	return (out);
}

std::string	Form::getName() const
{
	return name;
}

bool Form::getSign() const
{
	return sign;
}

int Form::getReqGrade() const
{
	return req_grade;
}
int Form::getExGrade() const
{
	return ex_grade;
}

void Form::beSigned(const Bureaucrat &var)
{
	if (var.getGrade() <= req_grade)
	{
		sign = true;
		std::cout << name << " form signed by " << var.getName() << std::endl;
		return;
	}
	std::cout << name << " form couldn't sign." << std::endl;
	throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "[FORM Exception] Grade is too high!";
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return "[FORM Exception] Grade is too low!";
}