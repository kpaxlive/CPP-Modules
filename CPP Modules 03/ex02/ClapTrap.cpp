#include "ClapTrap.h"

ClapTrap::ClapTrap()
{
	std::cout << "[ClapTrap] Default constructor called!\n";
	name = "NoName";
	hit_points = 10;
	energy = 10;
	attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "[ClapTrap] Name constructor called!\n";
	this->name = name;
	hit_points = 10;
	energy = 10;
	attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "[ClapTrap] Copy constructor called!\n";
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "[ClapTrap] Copy assignment operator called!\n";
	if(this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy = other.energy;
		this->attack_damage = other.attack_damage;
	}
	return(*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] Destructor called!\n";
}


void ClapTrap::attack(const std::string& target)
{
	if(hit_points <= 0)
	{
		std::cout << "[ClapTrap] " << name << " is dead, can't attack!\n";
		return;
	}
	else if(energy <= 0)
	{
		std::cout << "[ClapTrap] " << name << " has no energy, can't attack!\n";
		return;
	}

	std::cout << "[ClapTrap] " << name <<" attacks " << target << std::endl;
	energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if((hit_points - amount) <= 0)
		std::cout << "[ClapTrap] " << name << " took " << amount << " amount of damage and dead!\n";
	else
		std::cout << "[ClapTrap] " << name << " took " << amount << " amount of damage!\n";
	hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(energy > 0 && hit_points > 0)
	{
		hit_points += amount;
		std::cout << "[ClapTrap] " << name << " repaired " << amount << " of Health!\n";
		energy--;
	}
	else if(hit_points <= 0)
		std::cout << "[ClapTrap] " << name << " is already dead!\n";
	else
		std::cout << "[ClapTrap] " << name << " has no energy to repair health!\n";
}