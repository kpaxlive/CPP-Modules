#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: Invalid Argument Count" << std::endl;
		return 1;
	}
	Btc btc;
	btc.calculate(av[1]);
	return 0;
}
