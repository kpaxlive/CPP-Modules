#include "RPN.hpp"
#include <iostream>

Rpn::Rpn() {}

Rpn::Rpn(const Rpn &var)
{
	*this = var;
}

Rpn &Rpn::operator=(const Rpn &var)
{
	if(this == &var)
		return *this;
	*this = var;
	return *this;
}

Rpn::~Rpn() {}

void Rpn::compute(std::stack<double> &numbers, char operation)
{
	double a, b;

	b = numbers.top();
	numbers.pop();
	a = numbers.top();
	numbers.pop();

	switch (operation)
	{
	case '+':
		numbers.push(a + b);
		break;
	case '-':
		numbers.push(a - b);
		break;
	case '*':
		numbers.push(a * b);
		break;
	case '/':
		numbers.push(a / b);
		break;
	default:
		break;
	}
}

void Rpn::calculate(std::string expression)
{
	for (size_t i = 0; i < expression.size(); i++)
	{
		char character = expression[i];

		if (isspace(character))
			continue;
		else if (isdigit(character))
			numbers.push(character - '0');
		else if (character == '+' || character == '-' \
		|| character == '*' || character == '/')
		{
			if (numbers.size() < 2)
			{
				std::cerr << "Error: Invalid Input" << std::endl;
				return;
			}
			compute(numbers, character);
		}
	}
	if (numbers.size() != 1)
	{
		std::cerr << "Error: Invalid Input" << std::endl;
		return;
	}
	std::cout << numbers.top() << std::endl;
}
