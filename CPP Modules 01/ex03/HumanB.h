#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"

class HumanB
{
	private:
		std::string Bname;
		Weapon *ref_WeapB;

	public:
		HumanB(std::string Bname);
		void setWeapon(Weapon &WeapB);
		void attack();
};

#endif