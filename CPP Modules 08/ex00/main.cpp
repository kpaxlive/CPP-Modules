#include "easyfind.hpp"

const char *NotFound::what() const throw()
{
	return "Given parameter is not belong this container!\n";
}


int main()
{
	std::vector<int> ar;

	ar.push_back(5);
	ar.push_back(3);
	ar.push_back(1);
	ar.push_back(2);
	ar.push_back(4);

	std::vector<int>::iterator iter = easyfind(ar,5);
	std::size_t index = std::distance(ar.begin(), iter);
	std::cout << "Iterator's location value is " << *iter << std::endl;
	std::cout << "Iterator shows " << index << ". index!" << std::endl;  

	try
	{
		std::vector<int>::iterator iter = easyfind(ar,0);
		std::size_t index = std::distance(ar.begin(), iter);
		std::cout <<  index << std::endl;
		std::cout <<  *iter << std::endl;

	}
	catch(NotFound &e)
	{
		std::cout << e.what();
	}
}