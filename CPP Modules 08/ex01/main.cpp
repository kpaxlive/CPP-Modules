#include "Span.hpp"

int main() 
{
	Span sp = Span(10);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::vector<int> cp;
	cp.reserve(4);
	cp.push_back(18);
	cp.push_back(28);
	cp.push_back(38);
	cp.push_back(48);
	cp.push_back(58);

	sp.addMultiNumbers(cp);

	for(int i = 0; i < sp.sizeofArray(); i++)
		std::cout << "Span[" << i << "] = " << sp[i] << std::endl;
	
	try
	{
		sp.addNumber(45);
		sp.addMultiNumbers(cp);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(Span::SpanIsFull &e)
	{
		std::cout << e.what();
	}
	catch(Span::NoEnoughCapacity &e)
	{
		std::cout << e.what();
	}
	catch(Span::NoEnoughElements &e)
	{
		std::cout << e.what();
	}

	return 0; 
}