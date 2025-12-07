#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	fixedValue = 0;
}

Fixed::Fixed(const int n)
{
	this->fixedValue = n << fractionalValue;
}

Fixed::Fixed(const float n)
{
	this->fixedValue = roundf((n * (1 << fractionalValue)));
}

Fixed::Fixed(const Fixed& src)
{
	*this = src;
}

Fixed& Fixed::operator = (const Fixed& src)
{
	if (this != &src)
		this->setRawBits(src.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
}

float Fixed::toFloat( void ) const
{
	return (fixedValue / ((float)(1 << fractionalValue)));
}

int Fixed::toInt( void ) const
{
	return fixedValue >> fractionalValue;
}

int Fixed::getRawBits( void ) const
{
	return fixedValue;
}

void Fixed::setRawBits( int const raw )
{
	this->fixedValue = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return out;
}

bool Fixed::operator<(const Fixed& r) const
{
	return (this->getRawBits() < r.getRawBits());
}

bool Fixed::operator>(const Fixed& r) const
{
	return (this->getRawBits() > r.getRawBits());
}

bool Fixed::operator>=(const Fixed& r) const
{
	return (this->getRawBits() >= r.getRawBits());
}

bool Fixed::operator<=(const Fixed& r) const
{
	return (this->getRawBits() <= r.getRawBits());
}

bool Fixed::operator==(const Fixed& r) const
{
	return (this->getRawBits() == r.getRawBits());
}

bool Fixed::operator!=(const Fixed& r) const
{
	return (this->getRawBits() != r.getRawBits());
}

Fixed Fixed::operator+(const Fixed& r) const
{
	Fixed res;
	res.setRawBits(this->fixedValue + r.fixedValue);
	return res;
}

Fixed Fixed::operator-(const Fixed& r) const
{
	Fixed res;
	res.setRawBits(this->fixedValue - r.fixedValue);
	return res;
}

Fixed Fixed::operator*(const Fixed& r) const
{
	Fixed res;
	res.setRawBits(((long long)this->fixedValue * r.fixedValue) >> fractionalValue);
	return res;
}

Fixed Fixed::operator/(const Fixed& r) const
{
	Fixed res;
	res.setRawBits((this->fixedValue << fractionalValue) / r.fixedValue);
	return res;
}

Fixed& Fixed::operator++()
{
	this->fixedValue = this->fixedValue + 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->fixedValue = this->fixedValue + 1;
	return (temp);
}

Fixed& Fixed::operator--()
{
	this->fixedValue = this->fixedValue - 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->fixedValue = this->fixedValue - 1;
	return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);	
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}