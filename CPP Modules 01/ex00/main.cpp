#include "Zombie.h"

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

int main(void)
{
	Zombie *dead1 = newZombie("Furkan");
	dead1->announce();
	randomChump("Duhan");
	delete(dead1);
	return 0;
}