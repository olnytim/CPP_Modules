#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

using std::cout;
using std::endl;

class Fixed {
private:
	int					_value;
	static const int	_fract_value = 8;
public:
	Fixed();
	Fixed(const Fixed &toCopy);
	Fixed &operator=(const Fixed &toCopy);
	~Fixed();
	int		getRawBits( void ) const;
	void	setRawBits(int const raw);
};

#endif