#pragma once

#include <map>

class Btc
{
	std::map<std::string, float> data;
	public:
		Btc();
		Btc(const Btc &var);
		Btc &operator=(const Btc &var);
		~Btc();
		void calculate(const char *path);
		bool readInput(std::ifstream &inputFile);
		bool checkValue(float value);
		bool checkDate(std::string &date);
		bool checkTokens(std::vector<std::string> tokens);
		float getValue(std::map<std::string, float> data, std::string date);
		std::vector<std::string> getTokens(std::string &line);
};
