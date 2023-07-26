#include "caster.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "Wrong argument count!" << std::endl;
		return (1); 
	}
	std::string input = std::string(argv[1]);
	ScalarConverter::Convert(input);
}