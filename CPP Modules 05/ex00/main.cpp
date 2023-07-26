#include "Bureaucrat.h"

int main(void)
{
	try
	{
		Bureaucrat x("duhan", 150);
		std::cout << x << std::endl;
		x.decrement_grade();
		std::cout << x << std::endl;
	}
	catch(std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	return 0;
}