#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>
#include "Fixed.hpp"

class Point {
private:
	const Fixed _x;
	const Fixed _y;

public:
	Point();
	Point( const float num1, const float num2 );
	Point( const Point &toCopy );
	Point &operator=( const Point &toCopy );
	~Point();
	void	setX( const Fixed num1 );
	void	setY( const Fixed num2 );
	Fixed	getX() const;
	Fixed	getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif