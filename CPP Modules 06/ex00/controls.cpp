#include "caster.hpp"

int digit_control(std::string &str1)
{
	int i = -1;
	int counter = 0;
	int counter2 = 0;

	while(str1[++i] != '\0')
	{
		if((str1[i] <= 57 && str1[i] >= 48) || str1[i] == '.' || str1[i] == '-' || str1[i] == 'f')
		{
			if(str1[i] == '.')
				counter++;
			else if(str1[i] == 'f')
				counter2++;
			else if(str1[i] == '-' && i != 0)
				return TYPE_ERROR;
		}
		else
			return TYPE_ERROR;
	}
	if (counter > 1 || counter2 > 1 || (counter == 0 && counter2 >= 1) 
	|| (str1[i - 1] == '.') || (str1[i - 1] == 'f' && str1[i - 2] == '.'))
		return TYPE_ERROR;
	else if(counter == 1 && str1[i - 1] == 'f')
		return TYPE_FLOAT;
	else if(counter == 1)
		return TYPE_DOUBLE;
	else
		return TYPE_INT;
}

int char_control(std::string &str)
{
	if(isascii(str[0]))
	{
		if(isdigit(str[0]))
			return TYPE_INT;
		else
			return TYPE_CHAR;
	}
	return TYPE_ERROR;
}

int control_rest(std::string &str)
{
	int i = -1;
	int dot = 0;
	while(str[++i])
	{
		if(str[i] == '.')
		{
			dot++;
			i++;
		}
		if(dot == 1 && (str[i] != 48 && str[i] != 'f'))
			return 0;
	}
	return 1;
}

int detect_type(std::string &str)
{
	if(str.length() == 1)
		return (char_control(str));
	else
		return digit_control(str);
}
