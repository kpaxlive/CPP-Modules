#include "classes.hpp"

Data::Data()
{
	return;
}

Data::Data(int _value): value(_value)
{
	return;
}

Data::Data(const Data &var)
{
	*this = var;
}

Data &Data::operator=(const Data &var)
{
	if(this != &var)
		this->value = var.value;
	return *this;
}

Data::~Data()
{
	return;
}

int Data::get_value()
{
	return value;
}