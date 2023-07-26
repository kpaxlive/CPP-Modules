#pragma once

#include "Brain.h"
#include <iostream>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(const Animal &copy);
		virtual ~Animal();

		Animal& operator=(const Animal &other);
		virtual void makeSound() const;
		virtual std::string getType() const;
};


class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();

		Cat& operator=(const Cat &other);
		void makeSound() const;
		std::string getType() const;
		void check(const Cat &var) const ;
};

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();

		Dog& operator=(const Dog &other);
		void makeSound() const;
		std::string getType()const;
		void check(const Dog &var) const;
};


//-------------------------------------------------------------------//

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		virtual ~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal &other);
		virtual void makeSound() const;
		virtual std::string getType() const;
	
};

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &copy);
		~WrongCat();

		WrongCat& operator=(const WrongCat &other);
		void makeSound() const;
		std::string getType() const;
};

