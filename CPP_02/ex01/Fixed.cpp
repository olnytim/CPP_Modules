#include "Fixed.hpp"

Fixed::Fixed() {
	_value = 0;
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed &toCopy) {
	cout << "Copy constructor called" << endl;
	this->operator=(toCopy);
}

Fixed::~Fixed() {
	cout << "Destructor called" << endl;
}

int Fixed::getRawBits() const {
	return _value;
}

void Fixed::setRawBits(const int raw) {
	_value = raw;
}

Fixed& Fixed::operator=(const Fixed &toCopy) {
	cout << "Copy assignment operator called" << endl;
	_value = toCopy.getRawBits();
	return *this;
}

Fixed::Fixed(const int value) {
	_value = value << _fract_value;
	cout << "Int constructor called" << endl;
}

Fixed::Fixed(const float value) {
	_value = roundf(value * (1 << _fract_value));
	cout << "Float constructor called" << endl;
}

std::ostream &operator<<(std::ostream &out, const Fixed &toShow) {
	out << toShow.toFloat();
	return out;
}

float Fixed::toFloat() const {
	return (float)_value / (1 << _fract_value);
}

int	Fixed::toInt() const {
	return _value >> _fract_value;
}