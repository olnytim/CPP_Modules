#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	cout << "WrongCat: " << "Default constructor called" << endl;
	_type = "WrongCat";
	_brain = new Brain();
}

WrongCat::~WrongCat() {
	cout << "WrongCat: " << "Destructor called" << endl;
	delete _brain;
}

WrongCat& WrongCat::operator=(const WrongCat &toCopy) {
	cout << "WrongCat: " << "Copy assignment operator called" << endl;
	if (this != &toCopy) {
		WrongAnimal::operator=(toCopy);
		delete _brain;
		_brain = new Brain();
		*_brain = *toCopy._brain;
	}
	return *this;
}

WrongCat::WrongCat(const WrongCat &toCopy) : WrongAnimal(toCopy) {
	cout << "WrongCat: " << "Copy constructor called" << endl;
	_brain = new Brain();
	*_brain = *toCopy._brain;
}

void WrongCat::makeSound() const {
	cout << "WrongCat make sound 'Error 404 Meow!'" << endl;
}