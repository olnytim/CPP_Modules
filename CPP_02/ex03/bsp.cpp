#include "Point.hpp"
#include <stdio.h>

Fixed	abs(Fixed x)
{
	if (x < 0)	return x * -1;
	else	return x;
}

Fixed	sqrt( Point const a, Point const b, Point const c ) {
	Fixed val1 = (a.getX() * (b.getY() - c.getY()));
	Fixed val2 = (b.getX() * (c.getY() - a.getY()));
	Fixed val3 = (c.getX() * (a.getY() - b.getY()));
	Fixed result = (val1.getRawBits() + val2.getRawBits() + val3.getRawBits()) / 2;
	return (val1.getRawBits() + val2.getRawBits() + val3.getRawBits()) / 2;
}

bool	bsp( Point const a, Point const b, Point const c, Point const point ) {
	Fixed	ABC = abs(sqrt( a, b, c));
	Fixed	PAB = abs(sqrt( point, a, b));
	Fixed	PBC = abs(sqrt( point, b, c));
	Fixed	PCA = abs(sqrt( point, c, a));
	int x = 0;
	if ((ABC == PAB + PBC + PCA)) {
		x = 1;
	}
	return ((ABC == PAB + PBC + PCA) && PBC != 0 && PAB != 0 && PCA != 0);
}
