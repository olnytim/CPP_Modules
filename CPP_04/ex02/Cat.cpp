#include "Cat.hpp"

Cat::Cat() : Animal() {
	cout << "Cat: " << "Default constructor called" << endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::~Cat() {
	cout << "Cat: " << "Destructor called" << endl;
	delete _brain;
}

Cat& Cat::operator=(const Cat &toCopy) {
	cout << "Cat: " << "Copy assignment operator called" << endl;
	if (this == &toCopy) {
		Animal::operator=(toCopy);
		delete _brain;
		_brain = new Brain();
		*_brain = *toCopy._brain;
	}
	return *this;
}

Cat::Cat(const Cat &toCopy) : Animal(toCopy) {
	cout << "Cat: " << "Copy constructor called" << endl;
	_brain = new Brain();
	*_brain = *toCopy._brain;
}

void Cat::makeSound() const {
	cout << "Cat make sound 'Meow!'" << endl;
}