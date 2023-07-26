#pragma once
#include <iostream>

template <typename T>
void print(T &a)
{
	std::cout << a << std::endl;
}


template <typename T>
void iter(T *ar,int length, void (*function)(T&))
{
	for(int i = 0; i < length; i++)
		function(ar[i]);
}