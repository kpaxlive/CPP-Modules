#pragma once

#include <iostream>

class Brain
{
	private:
		std::string *ideas;
	
	public:
		Brain();
		Brain(const Brain &copy);
		~Brain();

		Brain& operator=(const Brain &other);
		std::string *getIdeas() const;
};

