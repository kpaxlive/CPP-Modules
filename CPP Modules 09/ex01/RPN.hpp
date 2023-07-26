#pragma once

#include <string>
#include <stack>

class Rpn
{
	std::stack<double> numbers;

	public:
		Rpn();
		Rpn(const Rpn &var);
		Rpn &operator=(const Rpn &var);
		~Rpn();

		void calculate(std::string expression);
		void compute(std::stack<double> &numbers, char operation);
};