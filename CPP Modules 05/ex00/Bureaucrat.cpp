#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(): name("NoName"), grade(150)
{
	std::cout << "Default constructor called!\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& var)
{
	*this = var;
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& var)
{
	setGrade(var.getGrade());
	std::cout << "Assigment operator overload called" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade): name(_name)
{
	setGrade(_grade);
	std::cout << "Name constructor called" << std::endl;
}

void Bureaucrat::setGrade(int _grade)
{
	if (_grade > 150)
		throw GradeTooLowException();
	else if (_grade < 1)
		throw GradeTooHighException();
	grade = _grade;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

std::string Bureaucrat::getName() const
{
	return name;
}

void Bureaucrat::increment_grade()
{
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrement_grade()
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade can't be that high!";
}


const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade can't be that low!";
}

std::ostream &operator<<(std::ostream &OUT , const Bureaucrat& var)
{
	OUT << "Bureaucrat " << var.getName() << "'s grade: " << var.getGrade();
	return (OUT);
}