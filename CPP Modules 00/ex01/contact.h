#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <string.h>

int name_control(std::string name);
int nickname_control(std::string name);
int number_control(std::string number);
int choice_control(std::string choice, int count);

class Contact
{
	private:
		std::string name;
		std::string surname;
		std::string nickname;
		std::string phoneNumber;
		std::string secret;
	public:
		void set_data(std::string iname, std::string  isurname, std::string inickname, std::string iphone, std::string isecret);
		std::string get_name();
		std::string get_surname();
		std::string get_nickname();
		std::string get_phoneNumber();
		std::string get_secret();
};

class PhoneBook
{
	private:
		Contact book[8];
	public:
		int add_User(int count);
		void show_Users(int count);
		void print_User(std::string a);
		void show_info(int i);
};

#endif