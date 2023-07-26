#include "ScavTrap.h"
#include "FragTrap.h"

int main()
{
	FragTrap furkan("Furkan");

	furkan.takeDamage(20);
	furkan.beRepaired(10);
	furkan.attack("Duhan");
	furkan.highFivesGuys();
}