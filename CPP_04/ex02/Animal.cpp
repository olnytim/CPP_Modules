#include "Animal.hpp"

Animal::Animal() : _type("NoName") {
	cout << "Animal: " << "Default constructor called" << endl;
}

Animal::~Animal() {
	cout << "Animal: " << "Destructor called" << endl;
}

Animal& Animal::operator=(const Animal &toCopy) {
	cout << "Animal: " << "Copy assignment operator called" << endl;
	_type = toCopy._type;
	return *this;
}

Animal::Animal(const Animal &toCopy) {
	cout << "Animal: " << "Copy constructor called" << endl;
	*this = toCopy;
}

string Animal::getType() const {
	return _type;
}

void Animal::setType(const string Type) {
	_type = Type;
}
