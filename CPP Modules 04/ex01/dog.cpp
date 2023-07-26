#include "animal.h"

Dog::Dog()
{
	this->brain = new Brain();
	this->type = "Dog";
	std::cout << "[Dog] Default constructor called!\n";
}

Dog::Dog(const Dog &copy)
{
	this->brain = new Brain(*copy.brain);
	this->type = copy.type;
	std::cout << "[Dog] Copy constructor called!\n";
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "[Dog] Destructor called!\n";
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << "[Dog] Copy assignment operator called!\n";
	if(this != &other)
		this->type = other.type;
	if(this->brain)
		delete brain;
	this->brain = new Brain(*other.brain);
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

void Dog::check(const Dog &var) const {
	std::cout << std::endl;
	std::cout << "Now comparing two " << this->type << std::endl;
	std::cout << "My Brain's heap adress: " << this->brain << std::endl;
	std::cout << "Other's heap adress: " << var.brain << std::endl;
	std::cout << std::endl;
}