#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Invalid Argument Count" << std::endl;
		return 1;
	}
	Rpn rpn;
	rpn.calculate(av[1]);
	return 0;
}
