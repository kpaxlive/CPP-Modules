#pragma once

#include <vector>
#include <iostream>

class Span
{
	private:
		std::vector<int> store;
	
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &var);
		~Span();

		Span &operator=(const Span &var);
		void addNumber(int number);
		void addMultiNumbers(const std::vector<int> &numbers);
		int shortestSpan();
		int longestSpan();
		int sizeofArray();
		int operator[](int a);


	class SpanIsFull: public std::exception
	{
		public:
			const char *what() const throw();
	};

	class NoEnoughElements: public std::exception
	{
		public:
			const char *what() const throw();
	};

	class NoEnoughCapacity: public std::exception
	{
		public:
			const char *what() const throw();
	};
};