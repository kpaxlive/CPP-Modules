#pragma once
#include <iostream>

template <class T>
class Array
{
	private:
		T *array;
		unsigned int arr_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T> &var);
		~Array();

		Array<T> &operator=(const Array<T> &var);
		T &operator[](unsigned int a);
		int size();

		class OverRange: public std::exception
		{
			public:
				const char *what() const throw();
		};
};

template <typename T>
Array<T>::Array()
{
	this->array = new T();
	this -> arr_size = 1;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->array = new T[n];
	this->arr_size = n;
	for (unsigned int i = 0; i < n; i++)
		this->array[i] = T();
}

template <typename T>
Array<T>::Array(const Array<T> &var)
{
	if(this == &var)
		return;
	this->array = new T[var.arr_size];
	this->arr_size = var.arr_size;
	for (int i = 0; i < static_cast<int>(var.arr_size); i++)
		this->array[i] = var.array[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &var)
{
	if(this == &var)
		return *this;
	delete[] array;
	this->array = new T[var.arr_size];
	this->arr_size = var.arr_size;
	for (int i = 0; i < static_cast<int>(var.arr_size); i++)
		this->array[i] = var.array[i];
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int a)
{
	if(a >= arr_size)
		throw OverRange(); 
	return array[a];
}

template <typename T>
int Array<T>::size()
{
	return this->arr_size;
}

template <typename T>
const char *Array<T>::OverRange::what() const throw()
{
	return "Index is out of bounds!\n";
}
