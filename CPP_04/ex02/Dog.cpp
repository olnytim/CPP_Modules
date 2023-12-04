#include "Dog.hpp"

Dog::Dog() : Animal() {
	cout << "Dog: " << "Default constructor called" << endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::~Dog() {
	cout << "Dog: " << "Destructor called" << endl;
	delete _brain;
}

Dog& Dog::operator=(const Dog &toCopy) {
	cout << "Dog: " << "Copy assignment operator called" << endl;
	Animal::operator=(toCopy);
	delete _brain;
	_brain = new Brain();
	*_brain = *toCopy._brain;
	return *this;
}

Dog::Dog(const Dog &toCopy) : Animal(toCopy) {
	cout << "Dog: " << "Copy constructor called" << endl;
	_brain = new Brain();
	*_brain = *toCopy._brain;
}

void Dog::makeSound() const {
	cout << "Dog make sound 'Bark!'" << endl;
}