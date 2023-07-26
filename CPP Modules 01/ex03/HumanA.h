#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"

class HumanA
{
	private:
		std::string Aname;
		Weapon *ref_WeapA;
	public:
		HumanA(std::string Aname, Weapon &WeapA);
		void attack();
};

#endif