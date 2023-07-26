#include "contact.h"

void set_header(void)
{
	std::cout << "														\n";
	std::cout << "				Welcome to Phonebook!			\n";
	std::cout << "														\n";
}

int main(void)
{
	std::string option;
	PhoneBook phoneBook;
	int count = -1;
	
	set_header();
	while(1)
	{
		std::cout << "Please enter a command [ADD, SEARCH, EXIT]\n";
		std::cout << "> ";
		std::getline(std::cin, option);
		
		if(option == "EXIT")
		{
			std::cout << "Have a good day! Bye\n";
			return (0);
		}
		else if(option == "ADD")
			count = phoneBook.add_User(count);
		else if(option == "SEARCH")
			phoneBook.show_Users(count);
		else
			std::cout << "Your command is not an option, try again: \n\n";
	}
}