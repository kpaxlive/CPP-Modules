#pragma once
#include "AForm.h"
#include <fstream>

class AForm;
class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string _target);
		PresidentialPardonForm(const PresidentialPardonForm &var);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator = (const PresidentialPardonForm &other);
		void execute(Bureaucrat const & executor);
};
