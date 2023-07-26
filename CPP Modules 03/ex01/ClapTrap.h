#pragma once

#include <iostream>

class ClapTrap
{
	protected:
		std::string name;
		int hit_points;
		int energy;
		int attack_damage;

	public:
		//constructors destructor and copy assignment operator;
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();

		ClapTrap& operator=(const ClapTrap &other);
		
		//ClapTrap's features;
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};