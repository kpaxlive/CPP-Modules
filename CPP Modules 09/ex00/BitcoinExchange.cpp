#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>

Btc::Btc()
{
	std::ifstream database;
	database.open("./data.csv");
	if (!database.is_open())
	{
		std::cout << "database couldn't open." << std::endl;
		return;
	}
	std::string line;
	std::getline(database, line);
	if (line != "date,exchange_rate")
		std::cout << "database content is not correct." << std::endl;
	while(std::getline(database, line))
	{
		std::string key, value;
		try
		{
			key = line.substr(0, 10);
			value = line.substr(11);
			data[key] = std::stof(value);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	database.close();
}

Btc::Btc(const Btc &var)
{
	*this = var;
}

Btc &Btc::operator=(const Btc &var)
{
	if(this == &var)
		return *this;
	*this = var;
	return *this;
}

Btc::~Btc() {}

bool Btc::checkDate(std::string &date)
{
	std::stringstream ss(date);
	std::vector<std::string> tokens;
	std::string item;

	while (std::getline(ss, item, '-'))
		tokens.push_back(item);
	for (size_t i = 0; i < tokens.size(); i++)
		for (size_t x = 0; x < tokens[i].size(); x++)
			if (std::isalpha(tokens[i][x]))
			{
				std::cerr << "Error: not a correct date." << std::endl;
				return false;
			}
		
	if (tokens.size() != 3 || tokens[0].size() != 4 || tokens[1].size() != 2 || tokens[2].size() != 2 ||\
		std::stoi(tokens[1]) < 1 || std::stoi(tokens[1]) > 12 ||\
		std::stoi(tokens[2]) < 1 || std::stoi(tokens[2]) > 31)
	{
		std::cerr << "Error: not a correct date." << std::endl;
		return false;
	}
	return true;
}

bool Btc::checkValue(float value)
{
	if (value <= 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	else if (value > 1000)
	{
		std::cerr << "Error: too large number." << std::endl;
		return false;
	}
	return true;
}

bool Btc::checkTokens(std::vector<std::string> tokens)
{
	if (tokens.size() != 3 || tokens[1] != "|")
	{
		std::cerr << "Error: bad input => ";
		for (size_t i = 0; i < tokens.size(); i++)
			std::cout << tokens[i] << " ";
		std::cout << std::endl;
		return false;
	}
	return true;
}

std::vector<std::string> Btc::getTokens(std::string &line)
{
	std::stringstream ss(line);
	std::vector<std::string> tokens;
	std::string item;
	
	while (std::getline(ss, item, ' '))
		tokens.push_back(item);
	return tokens;
}

float Btc::getValue(std::map<std::string, float> data, std::string date)
{
	std::map<std::string, float>::const_iterator iter = data.find(date);
    if (iter != data.end()) {
        return iter->second;
    }

    for (std::map<std::string, float>::const_reverse_iterator it = data.rbegin(); it != data.rend(); ++it) {
        if (it->first < date) {
            return it->second;
        }
    }
	return -1;
}

bool Btc::readInput(std::ifstream &inputFile)
{
	std::string line;
	getline(inputFile, line);
	if (line != "date | value")
		return false;
	std::vector<std::string> tokens;
	while (getline(inputFile, line))
	{
		tokens = getTokens(line);
		if (!checkTokens(tokens))
			continue;
		if (!checkDate(tokens[0]))
			continue;
		if (!checkValue(stof(tokens[2])))
			continue;
		float value = getValue(data, tokens[0]);
		if (value == -1)
		{
			std::cerr << "Data couldn't find." << std::endl;
			continue;
		}
		std::cout << tokens[0] << " => " << tokens[2] << " = " << value * std::stof(tokens[2]) << std::endl;
	}
	if (tokens.empty())
		std::cerr << "There's nothing to compute in file" << std::endl;
	return true;
}

void Btc::calculate(const char *path)
{
	std::ifstream inputFile;
	inputFile.open(path);
	if (!inputFile.is_open())
	{
		std::cerr << "inputFile couldn't open." << std::endl;
		return;
	}
	if (!readInput(inputFile))
	{
		std::cerr << "inputFile content is not correct." << std::endl;
		return;
	}
}
