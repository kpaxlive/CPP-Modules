#include "contact.h"

int PhoneBook::add_User(int count)
{
		static int a;
		std::string set_name;
		std::string set_surname;
		std::string set_nickname;
		std::string set_phoneNumber;
		std::string set_secret;

		std::cout << "Please enter the name (without spaces and digits): ";
		std::getline(std::cin, set_name);
		if(!name_control(set_name))
			return (count);
		std::cout << "Please enter the surname (without spaces and digits): ";
		std::getline(std::cin, set_surname);
		if(!name_control(set_surname))
			return (count);
		std::cout << "Please enter the nickname (without spaces): ";
		std::getline(std::cin, set_nickname);
		if(!nickname_control(set_nickname))
			return (count);
		std::cout << "Please enter the phone number(Anything except numbers is not allowed): ";
		std::getline(std::cin, set_phoneNumber);
		if(!number_control(set_phoneNumber))
			return (count);
		std::cout << "Please enter the secret: ";
		std::getline(std::cin, set_secret);
		if(!set_secret[0])
		{
			std::cout << "Your input is not valid! Returned the menu : \n\n";
			return (count);
		}
		if(a == 8)
			a = 0;
		book[a++].set_data(set_name, set_surname, set_nickname, set_phoneNumber, set_secret);
		count++;
		if(count == 0)
			count = 1;
		if(count == 9)
			count = 8;
		return(count);
}

void PhoneBook::print_User(std::string a)
{
	if(a.length() > 10)
	{
		a = a.substr(0, 9);
		std::cout << "|";
		std::cout << a;
		std::cout << ".";
	}
	else
	{
		std::cout << "|";
		for (int i = 0; i < 10 - a.length(); i++)
			std::cout << ' ';
		std::cout << a;
	}
}



void PhoneBook::show_info(int i)
{
	std::cout << "Name = " << book[i].get_name() << std::endl;
	std::cout << "Surname = " << book[i].get_surname() << std::endl;
	std::cout << "Nickname = " << book[i].get_nickname() << std::endl;
	std::cout << "Phone number = " << book[i].get_phoneNumber() << std::endl;
	std::cout << "Secret = " << book[i].get_secret() << std::endl;
}

void PhoneBook::show_Users(int count)
{
	std::string choice;
	int a;
	if(count < 0)
	{
		std::cout << "There is no user in PhoneBook, add user to display them!\n";
		return ;
	}
	std::cout << "|----------------------------------------|" << std::endl;
	std::cout << "|  Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------------------------------------|" << std::endl;
	for (int i = 0; i < count; i++)
	{	
		std::cout << "|      " << i;
		print_User(book[i].get_name());
		print_User(book[i].get_surname());
		print_User(book[i].get_nickname());
		std::cout << "|";
		std::cout << "\n|----------------------------------------|" << std::endl;
	}
	std::cout << "Enter the index number of contact's information you wanna display\n";
	std::cout << "> ";
	std::getline(std::cin, choice);
	if(!choice_control(choice, count))
		return ;
	else
	{
		char b[choice.length()];
		strcpy(b, choice.c_str());
		a = atoi(b);
		std::cout << "\n*** Informations of index " << a << " **"<< std::endl;
		show_info(a);
		std::cout << "\n";
	}
}