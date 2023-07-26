#include <iostream>

int main(void)
{
	std::string aa = "HI THIS IS BRAIN";
	std::string *a_pointer = &aa;
	std::string &a_referance = aa;

	std::cout << &aa << std::endl;
	std::cout << a_pointer << std::endl;
	std::cout << &a_referance << std::endl; 

	std::cout << aa << std::endl;
	std::cout << *a_pointer << std::endl;
	std::cout << a_referance << std::endl;

	return (0);
}