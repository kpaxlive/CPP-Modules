#include "caster.hpp"
#include <limits>
#include <math.h>

void char_help(std::string &str)
{
	if(control_rest(str))
	{
		int number;
		number = atoi(str.c_str());
		if((number >= 0 && number < 32) || number == 127)
			std::cout << "char: Non Displayable" << std::endl;
		else if(number < 0 || number > 127)
			std::cout << "char: imposible" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
	}
	else
		std::cout << "char: imposible" << std::endl;
}

void write_char(std::string &str, int a)
{
	if(a == 0)
		std::cout << "char: imposible\n";
	else if(a == 1)
		std::cout << "char: '" << str << "'" << std::endl;
	else if(a >= 2 && a <= 4)
		char_help(str);
}

void write_int(std::string &str, int a)
{
	if(a == 0)
		std::cout << "int: imposible\n";
	else if(a == 1)
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	else if(a >= 2 && a <= 4)
	{
		if(atof(str.c_str()) > std::numeric_limits<int>::max() || atof(str.c_str()) < std::numeric_limits<int>::min())
			std::cout << "int: Over integer limits" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(atof(str.c_str())) << std::endl;
	}
}

void write_double(std::string &str, int a)
{
	if (str == "-inf" || str == "+inf" || str == "inf"|| str == "nan") 
	{
       std::cout << "double: " << str << std::endl;
       return;
    }
	else if(str == "-inff" || str == "+inff" || str == "inff"|| str == "nanf")
	{
		str.pop_back();
		std::cout << "double: " << str << std::endl;
		return;
	}
	if(a == 0)
		std::cout << "double: imposible\n";
	else if(a == 1)
		std::cout << "double: " << static_cast<double>(str[0]) << ".0" <<  std::endl;
	else if(a >= 2 && a <= 4)
	{
		if(atof(str.c_str()) > std::numeric_limits<double>::max() || atof(str.c_str()) < std::numeric_limits<double>::lowest())
			std::cout << "double: Over double limits" << std::endl;
		else if ((atof(str.c_str()) == (floor(atof(str.c_str())))))
				std::cout<< "Double : "<< static_cast<double>(atof(str.c_str())) << ".0"<<std::endl;
			else
			 	std::cout<< "Double : "<< static_cast<double>(atof(str.c_str())) << std::endl;
	}
}

void write_float(std::string &str, int a)
{
	if (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf") 
	{
        std::cout << "float: " << str << std::endl;
        return;
    }
	else if(str == "-inf" || str == "+inf" || str == "inf" || str == "nan")
	{
		std::cout << "float: " << str << "f" << std::endl;
        return;
	}
	if(a == 0)
		std::cout << "float: imposible\n";
	else if(a == 1)
		std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
	else if(a >= 2 && a <= 4)
	{
		if(atof(str.c_str()) > std::numeric_limits<float>::max() || atof(str.c_str()) < std::numeric_limits<float>::lowest())
			std::cout << "float: Over float limits" << std::endl;
		else if((atof(str.c_str())) == floor(atof(str.c_str())))
			std::cout << "float: " << static_cast<float>(atof(str.c_str())) << ".0f" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(atof(str.c_str())) << "f" << std::endl;
	}
}