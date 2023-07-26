#include "replace.h"

void write_file(int counter, std::string buffer, char **argv)
{
	std::ofstream W_fileName;
	std::string wanna = std::string(argv[2]);
	std::string changed = std::string(argv[3]);
	int position;
	int i = -1;

	W_fileName.open(std::string(argv[1]) + ".replace");
	while(i++ < counter)
	{
		position = buffer.find(wanna, i);
		if(position != -1 && position == i)
		{
			W_fileName << changed;
			i += wanna.length() -1;
		}
		else
			W_fileName << buffer[i];
	}
	W_fileName.close();
}


int main(int argc, char **argv)
{
	std::ifstream R_fileName;
	std::string buffer;
	int counter = 0;
	char buff;
	if(argc == 4)
	{
		R_fileName.open((std::string)argv[1]);
		if(R_fileName.fail())
		{
			std::cout << "File not found!\n";
			return (1);
		}
		while(R_fileName >> std::noskipws >> buff && !R_fileName.eof())
		{
			buffer += buff;
			counter++;
		}
		R_fileName.close();
		write_file(counter, buffer, argv);
	}
	else
	{
		std::cout << "Invalid input! There must be three parameters...\n";
		return (1);
	}
	return (0);
}