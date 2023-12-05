#include "AMateria.hpp"

AMateria::AMateria() : type("default") {
	cout << "AMateria: Default constructor called" << endl;
}

AMateria::AMateria(const string &type) : {
	cout << "AMateria: Name constructor called" << endl;
	this->type = type;
}

AMateria& AMateria::operator=(const AMateria &toCopy) {
	cout << "AMateria: Copy assignment operator called" << endl;
	if (*this != toCopy) {
		*this->type = toCopy.type;
	}
	return *this;
}

AMateria::AMateria(const AMateria &toCopy) {
	cout << "AMateria: Copy constructor called" << endl;
	AMateria::operator=(toCopy);
}

AMateria::~AMateria() {
	cout << "AMateria: Destructor called" << endl;
}

string & AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter &target) {
	(void)target;
}