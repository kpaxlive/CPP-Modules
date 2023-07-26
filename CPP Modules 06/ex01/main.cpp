#include "classes.hpp"
#include <iostream>

int main()
{
	Data data(42);

	uintptr_t ptr = Serializer::serialize(&data);

	Data *object = Serializer::deserialize(ptr);

	std::cout << &data << "  **Original" <<std::endl;
	std::cout << ptr << "   **Serialized" <<std::endl;
	std::cout << object << "  **Deserialized"<<std::endl;
	std::cout << ((&data == object) ? "equal!\n" : "not equal!\n");
}