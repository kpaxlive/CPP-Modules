# include "ScavTrap.h"

int main()
{
	ScavTrap furkan("Furkan");
	ClapTrap duhan("Duhan");

	furkan.attack("Duhan");
	duhan.attack("Furkan");
	furkan.takeDamage(20);
	duhan.takeDamage(20);
	duhan.attack("Furkan");
	furkan.attack("Duhan");
	furkan.beRepaired(10);
	furkan.guardGate();
}