#include "Zombie.h"

Zombie*    zombieHorde( int N, std::string name )
{
	int i = -1;
	Zombie *multiple_z;

	multiple_z = new Zombie[N];
	while(++i < N)
	{
		multiple_z[i].set_name(name);
		announce(multiple_z[i].whats_name());
	}
	return (multiple_z);
}