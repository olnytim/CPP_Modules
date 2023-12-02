#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	cout << "WrongAnimal: " << "Default constructor called" << endl;
}

WrongAnimal::~WrongAnimal() {
	cout << "WrongAnimal: " << "Destructor called" << endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &toCopy) {
	cout << "WrongAnimal: " << "Copy assignment operator called" << endl;
	_type = toCopy._type;
	return *this;
}

WrongAnimal::WrongAnimal(const WrongAnimal &toCopy) {
	cout << "WrongAnimal: " << "Copy constructor called" << endl;
	*this = toCopy;
}

void WrongAnimal::makeSound() const {
	cout << "WrongAnimal make sound 'Error 404'" << endl;
}

string WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::setType(const string Type) {
	_type = Type;
}