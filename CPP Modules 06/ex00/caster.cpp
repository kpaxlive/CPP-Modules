#include "caster.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Converter constructor called!" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& var)
{
	*this = var; 
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& var)
{
	if(this != &var)
		*this = var;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Converter Destructor called!" << std::endl;
}

void ScalarConverter::Convert(std::string &str)
{
	int a = detect_type(str);
	write_char(str, a);
	write_int(str, a);
	write_float(str,a);
	write_double(str, a);
}
