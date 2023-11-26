#include "Point.hpp"
#include <stdio.h>

Fixed	abs(Fixed x)
{
	if (x < 0)	return x * -1;
	else	return x;
}

Fixed	sqrt( Point const a, Point const b, Point const c ) {
	Fixed val1 = (a.getX() * (b.getY() - c.getY()));
//	printf("val1: %d\n", val1.getRawBits());
	Fixed val2 = (b.getX() * (c.getY() - a.getY()));
//	printf("val2: %d\n", val2.getRawBits());
	Fixed val3 = (c.getX() * (a.getY() - b.getY()));
	Fixed result = (val1.getRawBits() + val2.getRawBits() + val3.getRawBits()) / 2;
//	printf("val3: %d\n", val3.getRawBits());
//	printf("result: %d\n\n", result.getRawBits());
	return (val1.getRawBits() + val2.getRawBits() + val3.getRawBits()) / 2;
}

bool	bsp( Point const a, Point const b, Point const c, Point const point ) {
	Fixed	ABC = abs(sqrt( a, b, c));
//	printf("ABC: %d\n", ABC.getRawBits());
	Fixed	PAB = abs(sqrt( point, a, b));
//	printf("PAB: %d\n", PAB.getRawBits());
	Fixed	PBC = abs(sqrt( point, b, c));
//	printf("PBC: %d\n", PBC.getRawBits());
	Fixed	PCA = abs(sqrt( point, c, a));
//	printf("PCA: %d\n", PCA.getRawBits());
	int x = 0;
	if ((ABC == PAB + PBC + PCA)) {
		x = 1;
	}
//	printf("%d\n", x);
	return ((ABC == PAB + PBC + PCA) && PBC != 0 && PAB != 0 && PCA != 0);
}
