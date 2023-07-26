#pragma once
#include <iostream>
#include <vector>

class NotFound: public std::exception
{
	public:
		const char *what() const throw();
};

template <typename T>
typename T::iterator easyfind(T &co, int b)
{
	typename T::iterator iter;
	iter = std::find(co.begin(), co.end(), b);
	if(iter != co.end())
		return iter;
	throw NotFound();
}