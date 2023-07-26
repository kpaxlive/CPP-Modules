#pragma once

#include <iostream>

# define floatToFixed(number) (number * (float)(1 << fractionalBits))
# define fixedToFloat(number) ((float)number / float(1 << fractionalBits))

class Fixed
{
	int					fixedPointNumber;
	static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed&);
		Fixed& operator = (const Fixed&);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator << (std::ostream&, const Fixed&);
