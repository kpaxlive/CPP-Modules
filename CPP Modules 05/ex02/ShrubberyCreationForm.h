#pragma once
#include "AForm.h"
#include <fstream>

class AForm;
class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string _target);
		ShrubberyCreationForm(const ShrubberyCreationForm &var);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator = (const ShrubberyCreationForm &other);
		void execute(Bureaucrat const & executor);
};
