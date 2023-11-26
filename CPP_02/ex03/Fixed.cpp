#include "Fixed.hpp"

Fixed::Fixed() {
	_value = 0;
}

Fixed::Fixed(int const value) {
	_value = value << _fract_value;
}

Fixed::Fixed(float const value) {
	_value = roundf(value * (1 << _fract_value));
}

Fixed::Fixed(const Fixed &toCopy) : _value(toCopy.getRawBits()) {}

Fixed::~Fixed() {
}

int Fixed::getRawBits() const {
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}


std::ostream &operator<<(std::ostream &out, const Fixed &toShow) {
	out << toShow.toFloat();
	return out;
}

float Fixed::toFloat() const {
	return ((float)_value / (float)(1 << _fract_value));
}

int	Fixed::toInt() const {
	return _value >> _fract_value;
}

bool Fixed::operator<(const Fixed &toCopy) const {
	return this->_value < toCopy.getRawBits();
}

bool Fixed::operator>(const Fixed &toCopy) const {
	return this->_value > toCopy.getRawBits();
}

bool Fixed::operator<=(const Fixed &toCopy) const {
	return this->_value <= toCopy.getRawBits();
}

bool Fixed::operator>=(const Fixed &toCopy) const {
	return this->_value >= toCopy.getRawBits();
}

bool Fixed::operator==(const Fixed &toCopy) const {
	return this->_value == toCopy.getRawBits();
}

bool Fixed::operator!=(const Fixed &toCopy) const {
	return this->_value != toCopy.getRawBits();
}

Fixed Fixed::operator+(const Fixed &toCopy) const {
//	Fixed result(this->_value + toCopy.getRawBits());
	Fixed result(this->toFloat() + toCopy.toFloat());
	return result;
}

Fixed Fixed::operator-(const Fixed &toCopy) const {
//	Fixed result(this->_value - toCopy.getRawBits());
	Fixed result(this->toFloat() - toCopy.toFloat());
	return result;
}

Fixed Fixed::operator*(const Fixed &toCopy) const {
	Fixed result(this->toFloat() * toCopy.toFloat());
	return result;
}

Fixed Fixed::operator/(const Fixed &toCopy) const {
	Fixed result(this->toFloat() / toCopy.toFloat());
	return result;
}

Fixed& Fixed::operator=(const Fixed &toCopy) {
	_value = toCopy.getRawBits();
	return *this;
}

Fixed Fixed::operator++() {
	++_value;
	return *this;
}

Fixed Fixed::operator++( int ) {
	Fixed temp = *this;
	++_value;
	return temp;
}

Fixed Fixed::operator--() {
	--_value;
	return *this;
}

Fixed Fixed::operator--( int ) {
	Fixed temp = *this;
	--_value;
	return temp;
}

Fixed Fixed::min(Fixed &num1, Fixed &num2) {
	if (num1 < num2)	return num2;
	else	return num1;
}

Fixed Fixed::max(Fixed &num1, Fixed &num2) {
	if (num1 > num2)	return num1;
	else	return num2;
}

const Fixed	Fixed::min(const Fixed &num1, const Fixed &num2) {
	if (num1 < num2)	return num2;
	else	return num1;
}

const Fixed	Fixed::max(const Fixed &num1, const Fixed &num2) {
	if (num1 > num2)	return num1;
	else	return num2;
}