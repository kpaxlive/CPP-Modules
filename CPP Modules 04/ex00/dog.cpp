#include "animal.h"

Dog::Dog()
{
	std::cout << "[Dog] Default constructor called!\n";
	this->type = "Dog";
}

Dog::Dog(const Dog &copy)
{
	std::cout << "[Dog] Copy constructor called!\n";
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "[Dog] Destructor called!\n";
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << "[Dog] Copy assignment operator called!\n";
	if(this != &other)
		this->type = other.type;
	return(*this);
}

void Dog::makeSound() const
{
	std::cout << "Some dog sounds\n";
}

std::string Dog::getType() const
{
	return(this->type);
}