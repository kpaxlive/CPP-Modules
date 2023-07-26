#include "iter.hpp"

int main()
{
	int int_array[] = {3, 4, 5};
	::iter(int_array, 3, &print);

	char char_array[] = {'a', 'b', 'c'};
	::iter(char_array, 3, &print);

	std::string string_array[] = {"ab", "cd", "ef"};
	::iter(string_array, 3, &print);
}