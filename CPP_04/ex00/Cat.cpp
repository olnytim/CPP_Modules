#include "Cat.hpp"

Cat::Cat() : Animal() {
	cout << "Cat: " << "Default constructor called" << endl;
	_type = "Cat";
}

Cat::~Cat() {
	cout << "Cat: " << "Destructor called" << endl;
}

Cat& Cat::operator=(const Cat &toCopy) {
	cout << "Cat: " << "Copy assignment operator called" << endl;
	_type = toCopy._type;
	return *this;
}

Cat::Cat(const Cat &toCopy) : Animal(toCopy) {
	cout << "Cat: " << "Copy constructor called" << endl;
	*this = toCopy;
}

void Cat::makeSound() const {
	cout << "Cat make sound 'Meow!'" << endl;
}