#include "Dog.hpp"

Dog::Dog() : Animal() {
	cout << "Dog: " << "Default constructor called" << endl;
	_type = "Dog";
}

Dog::~Dog() {
	cout << "Dog: " << "Destructor called" << endl;
}

Dog& Dog::operator=(const Dog &toCopy) {
	cout << "Dog: " << "Copy assignment operator called" << endl;
	_type = toCopy._type;
	return *this;
}

Dog::Dog(const Dog &toCopy) : Animal(toCopy) {
	cout << "Dog: " << "Copy constructor called" << endl;
	*this = toCopy;
}

void Dog::makeSound() const {
	cout << "Dog make sound 'Bark!'" << endl;
}