#include "FragTrap.h"

FragTrap::FragTrap()
{
	std::cout << "[FragTrap] Default constructor called!\n";
	this->name = "NoName";
	this->hit_points = 100;
	this->energy = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "[FragTrap] Name constructor called!\n";
	this->name = name;
	this->hit_points = 100;
	this->energy = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	std::cout << "[FragTrap] Copy constructor called!\n";
	*this = copy;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] Destructor called!\n";
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	std::cout << "[FragTrap] Copy assignment operator called!\n";
	if(this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy = other.energy;
		this->attack_damage = other.attack_damage;
	}
	return(*this);
}

void FragTrap::attack(const std::string &target)
{
	if(hit_points < 1)
	{
		std::cout << "[FragTrap] " << name << " is dead, can't attack!\n";
		return;
	}
	else if(energy < 1)
	{
		std::cout << "[FragTrap] " << name << " has no energy to attack!\n";
		return;
	}

	std::cout << "[FragTrap] " << name << " attacks " << target << std::endl;
	energy--;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "[FragTrap] " << name << " is called a highfive!\n";
}