#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		void set_name(std::string _name);
		std::string whats_name(void);
		~Zombie();
};

void announce(std::string name);
Zombie*    zombieHorde( int N, std::string name );

#endif