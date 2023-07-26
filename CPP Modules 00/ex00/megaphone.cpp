#include <iostream>
int main(int argc, char **argv)
{
	int i = 0, j;

if(argc > 1)
{
	while(argv[++i])
	{
		j = -1;
		while(argv[i][++j] != '\0')
		{
			if(argv[i][j] >= 97 && argv[i][j] <= 122)
				argv[i][j] = argv[i][j] - 32;
			std::cout << argv[i][j];
		}
	}
}
else
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
std::cout << "\n";
	return (0);
}