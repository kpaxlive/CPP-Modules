#include "ScavTrap.h"

ScavTrap::ScavTrap()
{
	std::cout << "[ScavTrap] Default constructor called!\n";
	this->name = "NoName";
	this->hit_points = 100;
	this->energy = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "[ScavTrap] Name constructor called!\n";
	this->name = name;
	this->hit_points = 100;
	this->energy = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	std::cout << "[ScavTrap] Copy constructor called!\n";
	*this = copy;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] Destructor called!\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "[ScavTrap] Copy assignment operator called!\n";
	if(this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy = other.energy;
		this->attack_damage = other.attack_damage;
	}
	return(*this);
}

void ScavTrap::attack(const std::string& target)
{
	if(hit_points < 1)
	{
		std::cout << "[ScavTrap] " << name << " is dead, can't attack!\n";
		return;
	}
	else if(energy < 1)
	{
		std::cout << "[ScavTrap] " << name << " has no energy to attack!\n";
		return;
	}

	std::cout << "[ScavTrap] " << name << " attacks " << target << std::endl;
	energy--;
}

void ScavTrap::guardGate()
{
	std::cout << "[ScavTrap] "<< name << " is now in Gate keeper mode.\n";
}