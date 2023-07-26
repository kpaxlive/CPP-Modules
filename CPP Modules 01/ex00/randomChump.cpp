#include "Zombie.h"

void randomChump(std::string name)
{
	Zombie dead(name);
	dead.announce();
}