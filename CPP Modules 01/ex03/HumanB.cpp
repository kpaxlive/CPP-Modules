#include "HumanB.h"

HumanB::HumanB(std::string Bname)
{
	this->Bname = Bname;
}

void HumanB::setWeapon(Weapon &Weapon)
{
	this->ref_WeapB = &Weapon;
}

void HumanB::attack()
{
	std::cout << Bname << " attacks with their " << ref_WeapB->getType() << std::endl;
}