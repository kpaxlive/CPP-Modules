#include "animal.h"

Cat::Cat()
{
	this->brain = new Brain();
	this->type = "Cat";
	std::cout << "[Cat] Default constructor called!\n";
}

Cat::Cat(const Cat &copy)
{
	this->brain = new Brain(*copy.brain);
	this->type = copy.type;
	std::cout << "[Cat] Copy constructor called!\n";
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "[Cat] Destructor called!\n";
}


Cat& Cat::operator=(const Cat &other)
{
	std::cout << "[Cat] Copy assignment operator overload called!\n";
	if(this != &other)
		this->type = other.type;
	if(this->brain)
		delete brain;
	this->brain = new Brain(*other.brain);
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

void Cat::check(const Cat &var) const {
	std::cout << std::endl;
	std::cout << "Now comparing two " << this->type << std::endl;
	std::cout << "My Brain's heap adress: " << this->brain << std::endl;
	std::cout << "Other's heap adress: " << var.brain << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}