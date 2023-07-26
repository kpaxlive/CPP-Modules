#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "[PresidentialPardonForm] Default constructor called!\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string _target) : AForm("PresidentialPardonForm", 25, 5) 
{
	target = _target;
	std::cout << "[PresidentialPardonForm] Name constructor called!\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &var) : AForm("PresidentialPardonForm", 25, 5)
{
	*this = var;
	std::cout << "[PresidentialPardonForm] Copy constructor called!\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm] Destructor called!\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm &other)
{
	target = other.target;
	std::cout << "[PresidentialPardonForm] Copy assignment operator overload called!\n";
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor)
{
	if (executor.getGrade() > getExGrade())
		throw GradeTooLowException();
	else if (!getSign())
		throw FormNotSignedException();
	this->ex = true;
	std::cout << "Form executed succesfuly by " << executor.getName() << std::endl;
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}