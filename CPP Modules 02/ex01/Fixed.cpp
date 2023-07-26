#include "Fixed.h"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixedPointNumber = 0;
}

Fixed::Fixed(const int val)
{
    std::cout << "Int constructor called" << std::endl;
	fixedPointNumber = floatToFixed(val);
}

Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called " << std::endl;
	fixedPointNumber = roundf(floatToFixed(val));
}

Fixed::Fixed(const Fixed& object)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = object;
}

Fixed& Fixed::operator = (const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		fixedPointNumber = obj.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return fixedPointNumber;
}

void Fixed::setRawBits(int const raw)
{
	fixedPointNumber = raw;
}

float	Fixed::toFloat(void) const
{
	return (fixedToFloat(fixedPointNumber));
}

int		Fixed::toInt(void) const
{
	return (fixedPointNumber >> fractionalBits);
}

std::ostream& operator << (std::ostream& out, const Fixed &a)
{
	return (out << a.toFloat());
}