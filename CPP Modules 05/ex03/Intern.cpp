#include "Intern.h"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &var) {
	*this = var;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &var) {
	(void)var;
	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

const char	*Intern::FormDoesntExistException::what() const throw()
{
	return "[Intern Exception] Form Doesn't Exist";
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			switch (i)
			{
			case 0:
				return (new ShrubberyCreationForm(target));
				break;
			case 1:
				return (new RobotomyRequestForm(target));
				break;
			case 2:
				return (new PresidentialPardonForm(target));
				break;
			}
		}
	}
	throw FormDoesntExistException();
}