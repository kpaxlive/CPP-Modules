#include "classes.hpp"

Serializer::Serializer()
{
	return;
}

Serializer::Serializer(const Serializer &var)
{
	*this = var;
}

Serializer &Serializer::operator=(const Serializer &var)
{
	if(this != &var)
		*this = var;
	return *this;
}

Serializer::~Serializer()
{
	return;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}