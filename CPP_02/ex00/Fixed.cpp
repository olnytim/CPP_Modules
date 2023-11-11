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
	cout << "getRawBits member function called" << endl;
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

Fixed& Fixed::operator=(const Fixed &toCopy) {
	cout << "Copy assignment operator called" << endl;
	_value = toCopy.getRawBits();
	return *this;
}