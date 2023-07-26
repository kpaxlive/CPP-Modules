#include "Zombie.h"

Zombie::~Zombie(void){}
Zombie::Zombie(void){}

void announce(std::string name)
{
	std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
	this->name = name;
}

std::string Zombie::whats_name(void)
{
	return(this->name);
}