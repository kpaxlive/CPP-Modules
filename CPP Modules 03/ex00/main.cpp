# include "ClapTrap.h"

int main()
{
	ClapTrap furkan("Furkan");
	ClapTrap duhan("Duhan");

	furkan.attack("Duhan");
	furkan.attack("Duhan");
	furkan.attack("Duhan");
	furkan.attack("Duhan");
	furkan.attack("Duhan");
	furkan.attack("Duhan");
	furkan.attack("Duhan");
	furkan.attack("Duhan");
	furkan.attack("Duhan");
	furkan.takeDamage(9);
	furkan.beRepaired(100);
	furkan.attack("Duhan");
}