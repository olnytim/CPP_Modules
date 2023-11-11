#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::~Point() {}

Point::Point(const float num1, const float num2) : _x(num1), _y(num2) {}

Point::Point(const Point &toCopy) : _x(toCopy._x), _y(toCopy._y){}

Point& Point::operator=(const Point &toCopy) {
	(Fixed)_x = toCopy.getX();
	(Fixed)_y = toCopy.getY();
	return *this;
}

Fixed Point::getX() const {
	return this->_x;
}

Fixed Point::getY() const {
	return this->_y;
}

void Point::setX(const Fixed num1) {
	(Fixed)_x = num1;
}

void Point::setY(const Fixed num2) {
	(Fixed)_y = num2;
}