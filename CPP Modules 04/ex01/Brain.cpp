#include "Brain.h"

Brain::Brain()
{
	std::cout << "Brain default constructor called!\n";

	this->ideas = new std::string[100];
	for ( int i = 0; i < 100; i++ )
		ideas[i] = "Thoughts";
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called!\n";
	std::string *hold = copy.getIdeas();
	this->ideas = new std::string[100];
	for(int i = 0; i < 100; i++)
		this->ideas[i] = hold[i];
}

Brain::~Brain()
{
	std::cout << "Brain destructor called!\n";
	delete [] this->ideas;
}

Brain& Brain::operator=(const Brain &other)
{
	for(int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return(*this);
}

std::string *Brain::getIdeas() const
{
	return (this->ideas);
}