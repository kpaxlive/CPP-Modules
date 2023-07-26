#include "animal.h"

WrongCat::WrongCat()
{
	std::cout << "[WrongCat] Default constructor called!\n";
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "[WrongCat] Copy constructor called!\n";
	*this = copy;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] Destructor called!\n";
}


WrongCat& WrongCat::operator=(const WrongCat &other)
{
	std::cout << "[WrongCat] Copy assignment operator called!\n";
	if(this != &other)
		this->type = other.type;
	return(*this);
}

void WrongCat::makeSound() const
{
	std::cout << "[WrongCat] Some WrongCat sounds\n";
}

std::string WrongCat::getType() const
{
	return(this->type);
}