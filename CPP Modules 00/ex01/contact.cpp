#include "contact.h"

void Contact::set_data(std::string iname, std::string  isurname, std::string inickname, std::string iphone, std::string isecret)
		{
			name = iname;
			surname = isurname;
			nickname = inickname;
			phoneNumber = iphone;
			secret = isecret;
		}

std::string Contact::get_name()
{
	return name;
}
std::string Contact::get_surname()
{
	return surname;
}
std::string Contact::get_nickname()
{
	return nickname;
}
std::string Contact::get_phoneNumber()
{
	return phoneNumber;
}
std::string Contact::get_secret()
{
	return secret;
}