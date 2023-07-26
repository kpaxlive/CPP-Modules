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

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		fixedPointNumber = obj.getRawBits();
	return *this;
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

// comprasion field

bool Fixed::operator > (const Fixed& var) const
{
	return (getRawBits() > var.getRawBits());
}

bool Fixed::operator < (const Fixed& var) const
{
	return (this->getRawBits() < var.getRawBits());
}

bool Fixed::operator >= (const Fixed& var) const
{
	return (getRawBits() >= var.getRawBits());
}

bool Fixed::operator <=(const Fixed& var) const
{
	return (this->getRawBits() <= var.getRawBits());
}

bool Fixed::operator == (const Fixed& var) const
{
	return (getRawBits() == var.getRawBits());
}

bool Fixed::operator != (const Fixed& var) const
{
	return (getRawBits() != var.getRawBits());
}

// arithmetic field

Fixed Fixed::operator + (const Fixed& var)
{
	return (Fixed)(toFloat() + var.toFloat());
}

Fixed Fixed::operator - (const Fixed& var)
{
	return (Fixed)(toFloat() - var.toFloat());
}

Fixed Fixed::operator * (const Fixed& var)
{
	return (Fixed)(toFloat() * var.toFloat());
}

Fixed Fixed::operator / (const Fixed& var)
{
	return (Fixed)(toFloat() / var.toFloat());
}

// pre/post increaments/decreaments

Fixed &Fixed::operator ++ ()
{
	++this->fixedPointNumber;
	return (*this);
}

Fixed Fixed::operator ++ (int)
{
	Fixed copy(*this);
	++*this;
	return copy;
}

Fixed &Fixed::operator -- ()
{
	--this->fixedPointNumber;
	return *this;
}

Fixed Fixed::operator -- (int)
{
	Fixed copy(*this);
	--*this;
	return copy;
}

// min-max

Fixed &Fixed::min(Fixed &fp1, Fixed &fp2)
{
	return fp1 < fp2 ? fp1 : fp2;
}

const Fixed &Fixed::min(const Fixed &fp1, const Fixed &fp2)
{
	return fp1 < fp2 ? fp1 : fp2;
}

Fixed &Fixed::max(Fixed &fp1, Fixed &fp2)
{
	return fp1 > fp2 ? fp1 : fp2;
}

const Fixed &Fixed::max(const Fixed &fp1, const Fixed &fp2)
{
	return fp1 > fp2 ? fp1 : fp2;
}



std::ostream& operator << (std::ostream& out, const Fixed &a)
{
	return (out << a.toFloat());
}