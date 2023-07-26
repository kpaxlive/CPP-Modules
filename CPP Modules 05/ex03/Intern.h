#pragma once

#include <iostream>
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

class Intern
{
	public:
		Intern();
		Intern(const Intern& var);
		Intern &operator=(const Intern& var);
		~Intern();

		AForm *makeForm(std::string name, std::string target);

		class FormDoesntExistException :public std::exception
		{
			public:
				const char *what() const throw();
		};		
};