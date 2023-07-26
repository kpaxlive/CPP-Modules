#include "animal.h"

AAnimal::AAnimal()
{
	std::cout << "[AAnimal] Default constructor called!\n";
	this->type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "[AAnimal] Copy constructor called!\n";
	*this = copy;
}

AAnimal::~AAnimal()
{
	std::cout << "[AAnimal] Destructor called!\n";
}

AAnimal& AAnimal::operator=(const AAnimal &other)
{
	std::cout << "[AAnimal] Copy assignment operator called!\n";
	if(this != &other)
		this->type = other.type;
	return(*this);
}

/*void AAnimal::makeSound() const
{
	std::cout << "[AAnimal] Some AAnimal sounds\n";
}*/

std::string AAnimal::getType() const
{
	return(this->type);
}