#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "[ShrubberyCreationForm] Default constructor called!\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string _target) : AForm("ShrubberyCreationForm", 145, 137) 
{
	target = _target;
	std::cout << "[ShrubberyCreationForm] Name constructor called!\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &var) : AForm("ShrubberyCreationForm", 145, 137)
{
	*this = var;
	std::cout << "[ShrubberyCreationForm] Copy constructor called!\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm] Destructor called!\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm &other)
{
	target = other.target;
	std::cout << "[ShrubberyCreationForm] Copy assignment operator overload called!\n";
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	if (executor.getGrade() > getExGrade())
		throw GradeTooLowException();
	else if (!getSign())
		throw FormNotSignedException();
	this->ex = true;
	std::cout << "Form executed succesfuly by " << executor.getName() << std::endl;
	std::ofstream file(target + "_shrubbery");			
	file << "               ,@@@@@@@," << std::endl;
	file << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	file << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	file << "       |o|        | |         | |" << std::endl;
	file << "       |.|        | |         | |" << std::endl;
	file << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	file.close();
}