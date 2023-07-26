#include "Array.hpp"

int main()
{
	Array<int> ar;
	Array<int> ar2(5);
	Array<int> ar3(ar2);
	Array<int> ar4(7);

	ar4[0] = 16;
	ar2[0] = 8;
	ar2 = ar4;
	ar4[0] = 4;

	std::cout << "array1 size :" << ar.size() << " ar[0]: " << ar[0] << std::endl; 
	std::cout << "array1 size :" << ar2.size() << " ar2[0]: "  << ar2[0] << std::endl;
	std::cout << "array1 size :" << ar3.size() << " ar3[0]: "  << ar3[0] <<std::endl;


	ar2[3] = 4;
	for (int i = 0; i < ar2.size(); i++)
		std::cout <<  "ar2[" << i << "]: '"  << ar2[i] << "' " << std::endl;

	Array <std::string> strings(6);
	strings[2] = "Furkan";
	for (int i = 0; i < strings.size(); i++)
		std::cout <<  "strings[" << i << "]: '"  << strings[i] << "' " << std::endl;

	try
	{
		std::cout << "array[duhan]: "  << ar2[-1] << std::endl;
		std::cout << "array[10]: "  << ar2[10] << std::endl;
	}
	catch(Array<int>::OverRange &e)
	{
		std::cout << std::string(e.what());
	}
}