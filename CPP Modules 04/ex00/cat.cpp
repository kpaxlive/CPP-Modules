#include "animal.h"

Cat::Cat()
{
	std::cout << "[Cat] Default constructor called!\n";
	this->type = "Cat";
}

Cat::Cat(const Cat &copy)
{
	std::cout << "[Cat] Copy constructor called!\n";
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "[Cat] Destructor called!\n";
}


Cat& Cat::operator=(const Cat &other)
{
	std::cout << "[Cat] Copy assignment operator called!\n";
	if(this != &other)
		this->type = other.type;
	return(*this);
}

void Cat::makeSound() const
{
	std::cout << "Some cat sounds\n";
}

std::string Cat::getType() const
{
	return(this->type);
}