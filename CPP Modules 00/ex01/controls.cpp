#include "contact.h"

int name_control(std::string name)
{
	int i = 0;
	if(!name[i])
	{
		std::cout << "Your input is not valid! Returned the menu :\n\n";
		return (0);
	}
	while(name[i])
	{
		if(!((name[i] <= 90 && name[i] >= 65) || (name[i] >= 97 && name[i] <= 122)))
		{
			std::cout << "Your input is not valid! Returned the menu :\n\n";
			return (0);
		}
					
		i++;
	}
	return (1);
}

int nickname_control(std::string name)
{
	int i = 0;
	if(!name[i])
	{
		std::cout << "Your input is not valid! Returned the menu : \n\n";
		return (0);
	}
	while(name[i] != '\0')
	{
		if (name[i] == ' ' || name[i] == '\t' || name[i] == '\v' || name[i] == '\f' || name[i] == '\n' || name[i] == '\r')
		{
			std::cout << "Your input is not valid! Returned the menu :\n";
			return (0);
		}
					
		i++;
	}
	return (1);
}

int number_control(std::string number)
{
	int i = 0;
	if(!number[i])
	{
		std::cout << "Your input is not valid! Returned the menu : \n\n";
		return (0);
	}
	while (number[i] != '\0')
	{
		if(!(number[i] <= 57 && number[i] >= 48))
		{
			std::cout << "Your input is not valid! Returned the menu : \n\n";
			return (0);
		}
		i++;
	}
	return (1);
}

int choice_control(std::string choice, int count)
{
	int i = -1;
	int a;
	while(choice[++i] != '\0')
	{
		if(!(choice[i] <= 57 && choice[i] >= 48))
		{
			std::cout << "Invalid input! Your input should be a number, returned to menu.\n";
				return (0);
		}
	}
	a = atoi(choice.c_str());
	if(a > count - 1)
	{
		std::cout << "User not found! Returned the menu.\n";
		return (0);
	}
	return (1);

}
