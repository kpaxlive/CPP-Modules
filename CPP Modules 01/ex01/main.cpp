#include "Zombie.h"

int main(void)
{
	Zombie *multiple_z = zombieHorde(8, "Furkan");
	delete[] multiple_z;
}