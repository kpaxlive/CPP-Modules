#include "AForm.h"

AForm::AForm() : name("No Name"), req_grade(150), ex_grade(150)
{
	sign = false;
	ex = false;
	std::cout << "Form constructor called" << std::endl;
}

AForm::AForm(std::string _name, int reqGrade, int exGrade) : name(_name), req_grade(reqGrade), ex_grade(exGrade)
{
	if (this->req_grade < 1 || this->ex_grade < 1)
        throw AForm::GradeTooHighException();
    if (this->req_grade > 150 || this->ex_grade > 150)
        throw  AForm::GradeTooLowException();
	sign = false;
	ex = false;
	std::cout << "Form name constructor called" << std::endl;
}

AForm::AForm(const AForm &var) : name(var.getName()), req_grade(var.getReqGrade()), ex_grade(var.getExGrade())
{
	sign = var.getSign();
	ex = var.getEx();
	std::cout << "Form copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Form destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &var)
{
	sign = var.getSign();
	ex = var.getEx();
	std::cout << "Form assigment operator overload called" << std::endl;
	return (*this);
}

std::ostream &operator<<(std::ostream &out , const AForm& var)
{
	out << "Form " << var.getName() << (var.getSign() ? " is signed " : " not signed ") << (var.getEx() ? "and executed!" : "and not executed!");
	return (out);
}

std::string	AForm::getName() const
{
	return name;
}

bool AForm::getSign() const
{
	return sign;
}

bool AForm::getEx() const
{
	return ex;
}

int AForm::getReqGrade() const
{
	return req_grade;
}
int AForm::getExGrade() const
{
	return ex_grade;
}

void AForm::beSigned(const Bureaucrat &var)
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

const char *AForm::GradeTooHighException::what() const throw()
{
	return "[FORM Exception] Grade is too high!";
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "[FORM Exception] Grade is too low!";
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return "[FORM Exception] Form is not signed!";
}