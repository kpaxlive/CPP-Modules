#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "Intern.h"

int main()
{
	try{

	Bureaucrat	chad("Chad", 2);
	Intern		asd;
	AForm		*forms[5];

	forms[0] = asd.makeForm("shrubbery creation", "file");
	forms[1] = asd.makeForm("robotomy request", "Duhan");
	forms[2] = asd.makeForm("presidential pardon", "Furkan");
	forms[3] = asd.makeForm("robotomy request", "Duhan");
	//forms[4] = asd.makeForm("random request", "random");

	for (int i = 0; i < 5; ++i)
	{
		if (forms[i])
		{
			std::cout << std::endl << *(forms[i]) << "*******************" << std::endl;
			chad.signForm(*(forms[i]));
			chad.executeForm(*(forms[i]));
			std::cout << "\n";
		}
	}

	for (int i = 0; i < 5; i++)
		delete forms[i];
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}