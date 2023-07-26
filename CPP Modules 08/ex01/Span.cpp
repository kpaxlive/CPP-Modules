#include "Span.hpp"

Span::Span()
{
	this->store.reserve(1);
	std::cout << "An emtpy Span constructed!" << std::endl;
}

Span::Span(unsigned int N) 
{
	this->store.reserve(N);
	std::cout << N << " element capacity Span constructed!" << std::endl;
}

Span::Span(const Span &var)
{
	*this = var;
}

Span::~Span()
{
	return;
}

Span &Span::operator=(const Span &var)
{
	if(this != &var)
		this->store = var.store;
	return *this;
}

void Span::addNumber(int number)
{
	if(this->store.capacity() == this->store.size())
		throw SpanIsFull();
	this->store.push_back(number);
}

int Span::shortestSpan()
{
	if(this->store.size() < 2)
		throw NoEnoughElements();
	std::vector<int> tmp = store;
	std::sort(tmp.begin(), tmp.end());
	int distance = std::numeric_limits<int>::max();
	int size = tmp.size();
	for(int i = 0; i < (size - 1); i++)
		if((abs(tmp[i] - tmp[i+1])) < distance)
			distance = (abs(tmp[i] - tmp[i+1]));
	return distance;
}

int Span::longestSpan()
{
	if(this->store.size() < 2)
		throw NoEnoughElements();
	int min_element = *std::min_element(store.begin(), store.end());
	int max_element = *std::max_element(store.begin(), store.end());
	return max_element - min_element;
}

void Span::addMultiNumbers(const std::vector<int> &numbers)
{
	if((numbers.size() + store.size()) > store.capacity())
		throw NoEnoughCapacity();
	store.insert(store.end(), numbers.begin(), numbers.end());
}

int Span::sizeofArray()
{
	return this->store.size();
}

int Span::operator[](int a)
{
	return this->store[a];
}

const char *Span::SpanIsFull::what() const throw()
{
	return "Span is already full!\n";
}

const char *Span::NoEnoughElements::what() const throw()
{
	return "There is no enough elements in Span!\n";
}

const char *Span::NoEnoughCapacity::what() const throw()
{
	return "There is no enough capacity in Span!\n";
}