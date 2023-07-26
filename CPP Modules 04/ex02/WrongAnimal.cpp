#include "animal.h"

WrongAnimal::WrongAnimal()
{
	std::cout << "[WrongAnimal] Default constructor called!\n";
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "[WrongAnimal] Copy constructor called!\n";
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] Destructor called!\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "[WrongAnimal] Copy assignment operator called!\n";
	if(this != &other)
		this->type = other.type;
	return(*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "[WrongAnimal] Some WrongAnimal sounds\n";
}

std::string WrongAnimal::getType() const
{
	return(this->type);
}