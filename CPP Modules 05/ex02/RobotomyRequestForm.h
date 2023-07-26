#pragma once
#include "AForm.h"
#include <fstream>

class AForm;
class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string _target);
		RobotomyRequestForm(const RobotomyRequestForm &var);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator = (const RobotomyRequestForm &other);
		void execute(Bureaucrat const & executor);
};
