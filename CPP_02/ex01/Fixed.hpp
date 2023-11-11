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
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &toCopy);
	Fixed &operator=(const Fixed &toCopy);
	~Fixed();
	float	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits(int const raw);
};
std::ostream &operator<<(std::ostream &out, const Fixed &toShow);

#endif
