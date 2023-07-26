#include "Harl.h"

int main(int ac, char **av)
{
	Harl issue;
	
	if(av[1])
		issue.complain(av[1]);
	else
		std::cout << "Issue level not found!\n";
	return (0);
}