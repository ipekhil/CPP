#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <string>

class Fixed
{
private:
	int			fixedValue;
	static const int	fractionalValue = 8;
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed& src);
	Fixed& operator = (const Fixed& src);
	~Fixed();
	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	bool operator<(const Fixed& r) const;
	bool operator>(const Fixed& r) const;
	bool operator>=(const Fixed& r) const;
	bool operator<=(const Fixed& r) const;
	bool operator==(const Fixed& r) const;
	bool operator!=(const Fixed& r) const;
	Fixed operator+(const Fixed& r) const;
	Fixed operator-(const Fixed& r) const;
	Fixed operator*(const Fixed& r) const;
	Fixed operator/(const Fixed& r) const;
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);


};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif