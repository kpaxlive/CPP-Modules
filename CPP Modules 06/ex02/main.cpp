#include "classes.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base(){return;}

Base *generate(void)
{
	srand(time(NULL));
	int i = rand() % 3;
	if(i == 0)
		return new A;
	else if(i == 1)
		return new B;
	else
		return new C;
}

void identify(Base *p)
{

    try {
        if (dynamic_cast<A*>(p) != 0)
            std::cout << "Class is [A]" << std::endl;
        else if (dynamic_cast<B*>(p) != 0)
            std::cout << "Class is [B]" << std::endl;
        else if (dynamic_cast<C*>(p) != 0)
            std::cout << "Class is [C]" << std::endl;
    }
    catch (std::bad_cast& e)
	{
        std::cout << "Something wrong about casting!" << std::endl;
    }
}

void identify(Base &p)
{
	try {
    if (dynamic_cast<A*>(&p) != 0)
        std::cout << "Class is [A]" << std::endl;
    else if (dynamic_cast<B*>(&p) != 0)
        std::cout << "Class is [B]" << std::endl;
    else if (dynamic_cast<C*>(&p) != 0)
        std::cout << "Class is [C]" << std::endl;
    else
        std::cout << "Failed to cast to any known class" << std::endl;
}
	catch (std::exception& e) 
	{
   		 std::cout << "Something wrong about casting!" << std::endl;
	}
}

int main()
{
	Base *object = generate();
	B a;
	identify(object);
	identify(a);
}