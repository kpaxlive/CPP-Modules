#include "HumanA.h"

HumanA::HumanA(std::string Aname, Weapon &WeapA)
{
	this->ref_WeapA = &WeapA;
	this->Aname = Aname;
}

void HumanA::attack()
{
	std::cout << this->Aname << " attacks with their " << this->ref_WeapA->getType() << std::endl;
}

