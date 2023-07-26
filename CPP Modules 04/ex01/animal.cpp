#include "animal.h"

Animal::Animal()
{
	std::cout << "[Animal] Default constructor called!\n";
	this->type = "Animal";
}

Animal::Animal(const Animal &copy)
{
	std::cout << "[Animal] Copy constructor called!\n";
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "[Animal] Destructor called!\n";
}

Animal& Animal::operator=(const Animal &other)
{
	std::cout << "[Animal] Copy assignment operator called!\n";
	if(this != &other)
		this->type = other.type;
	return(*this);
}

void Animal::makeSound() const
{
	std::cout << "[Animal] Some Animal sounds\n";
}

std::string Animal::getType() const
{
	return(this->type);
}