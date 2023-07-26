#include "RobotomyRequestForm.h"
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "[RobotomyRequestForm] Default constructor called!\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string _target) : AForm("RobotomyRequestForm", 72, 45) 
{
	target = _target;
	std::cout << "[RobotomyRequestForm] Name constructor called!\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &var) : AForm("RobotomyRequestForm", 72, 45)
{
	*this = var;
	std::cout << "[RobotomyRequestForm] Copy constructor called!\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm] Destructor called!\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm &other)
{
	target = other.target;
	std::cout << "[RobotomyRequestForm] Copy assignment operator overload called!\n";
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	if (executor.getGrade() > getExGrade())
		throw GradeTooLowException();
	else if (!getSign())
		throw FormNotSignedException();
	std::cout << "Form executed succesfuly by " << executor.getName() << std::endl;
	this->ex = true;
	srand(time(NULL));
	std::cout << "Drrrrrrrrr" << std::endl;
	if (rand() % 2 == 0)
		std::cout << target << " has been robotomized succesfully" << std::endl;
	else
		std::cout << target << " couldn't robotomized" << std::endl;
}