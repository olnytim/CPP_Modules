#include "ICharacter.hpp"

ICharacter::ICharacter() {
	cout << "ICharacter: Default constructor called" << endl;
}

ICharacter::~ICharacter() {
	cout << "ICharacter: Destructor called" << endl;
}

ICharacter& ICharacter::operator=(const ICharacter &toCopy) {
	cout << "ICharacter: Copy assignment operator called" << endl;
	return *this;
}

ICharacter::ICharacter(const ICharacter &toCopy) {
	cout << "ICharacter: Copy constructor called" << endl;
	ICharacter::operator=(toCopy);
}