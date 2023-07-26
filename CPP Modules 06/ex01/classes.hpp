#ifndef CLASSES_H
#define CLASSES_H

#include <cstdint>

class Data
{
	private:
		int value;

	public:
		Data();
		Data(const Data &var);
		Data &operator=(const Data &var);
		Data(int _value);
		~Data();
		int get_value();
};

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer &var);
		Serializer &operator=(const Serializer &var);
		~Serializer();
		
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif