#pragma once

#include "Brain.h"
#include <iostream>

class AAnimal
{
	protected:
		std::string type;

	public:
		AAnimal();
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal();

		AAnimal& operator=(const AAnimal &other);
		virtual void makeSound() const = 0;
		virtual std::string getType() const;
};


class Cat : public AAnimal
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
};

class Dog : public AAnimal
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

