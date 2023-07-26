#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <stdlib.h>
#include <string.h>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(std::string name);
		void announce(void);
		~Zombie(void);
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif