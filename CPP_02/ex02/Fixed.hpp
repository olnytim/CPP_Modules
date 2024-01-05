#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

class Fixed {
private:
	int					_value;
	static const int	_fract_value = 8;
public:
	Fixed();
	Fixed( const int value );
	Fixed( const float value );
	Fixed( const Fixed &toCopy );
	bool operator>( const Fixed &toCopy ) const;
	bool operator<( const Fixed &toCopy ) const;
	bool operator>=( const Fixed &toCopy ) const;
	bool operator<=( const Fixed &toCopy) const;
	bool operator==( const Fixed &toCopy ) const;
	bool operator!=( const Fixed &toCopy ) const;
	Fixed &operator=( const Fixed &toCopy );
	Fixed operator+( const Fixed &toCopy ) const;
	Fixed operator-( const Fixed &toCopy ) const;
	Fixed operator*( const Fixed &toCopy ) const;
	Fixed operator/( const Fixed &toCopy ) const;
	Fixed operator++( int );
	Fixed operator--( int );
	Fixed operator++();
	Fixed operator--();
	~Fixed();
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( const int raw );
	float	toFloat( void ) const;
	static Fixed		min( Fixed &num1, Fixed &num2 );
	static Fixed		max( Fixed &num1, Fixed &num2 );
	static const Fixed	min( const Fixed &num1, const Fixed &num2 );
	static const Fixed	max( const Fixed &num1, const Fixed &num2 );
};

std::ostream &operator<<( std::ostream &out, const Fixed &toShow );

#endif
