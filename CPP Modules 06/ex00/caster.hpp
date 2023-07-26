#ifndef CASTER_H
#define CASTER_H

#define TYPE_ERROR 0
#define TYPE_CHAR 1
#define TYPE_INT 2
#define TYPE_DOUBLE 3
#define TYPE_FLOAT 4

#include <iostream>
#include <string>


class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& var);
		ScalarConverter& operator=(const ScalarConverter& var);
		~ScalarConverter();
		static void Convert(std::string &str);
};

int control_rest(std::string &str);
int detect_type(std::string &str);
void write_char(std::string &str,int a);
void write_int(std::string &str,int a);
void write_float(std::string &str,int a);
void write_double(std::string &str,int a);


#endif