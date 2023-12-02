#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	cout << "WrongCat: " << "Default constructor called" << endl;
	_type = "WrongCat";
}

WrongCat::~WrongCat() {
	cout << "WrongCat: " << "Destructor called" << endl;
}

WrongCat& WrongCat::operator=(const WrongCat &toCopy) {
	cout << "WrongCat: " << "Copy assignment operator called" << endl;
	_type = toCopy._type;
	return *this;
}

WrongCat::WrongCat(const WrongCat &toCopy) : WrongAnimal(toCopy) {
	cout << "WrongCat: " << "Copy constructor called" << endl;
	*this = toCopy;
}

void WrongCat::makeSound() const {
	cout << "WrongCat make sound 'Error 404 Meow!'" << endl;
}