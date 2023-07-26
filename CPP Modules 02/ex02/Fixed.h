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
		~Fixed();
		Fixed& operator = (const Fixed&);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		// comparison field
		bool operator > (const Fixed&) const;
		bool operator < (const Fixed&) const;
		bool operator >= (const Fixed&) const;
		bool operator <= (const Fixed&) const;
		bool operator == (const Fixed&) const;
		bool operator != (const Fixed&) const;
		// arithmetic field
		Fixed operator + (const Fixed&);
		Fixed operator - (const Fixed&);
		Fixed operator * (const Fixed&);
		Fixed operator / (const Fixed&);

		// pre/post increaments/decreaments
		Fixed operator ++ (int);
		Fixed &operator ++ ();
		Fixed operator -- (int);
		Fixed &operator -- ();

		// min-max
		static			Fixed &min(Fixed &, Fixed &);
		static 			Fixed &max(Fixed &, Fixed &);
		static const	Fixed &min(const Fixed &, const Fixed &);
		static const	Fixed &max(const Fixed &, const Fixed &);
};

std::ostream& operator << (std::ostream&, const Fixed&);
