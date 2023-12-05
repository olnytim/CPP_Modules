#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	cout << "Ice: Default constructor called" << endl;

}

Ice::~Ice() {
	cout << "Ice: Destructor called" << endl;
}

Ice& Ice::operator=(const Ice &toCopy) {
	cout << "Ice: Copy assignment operator called" << endl;
	if (*this != toCopy) {
		*this->type = toCopy.type;
	}
	return *this;
}

Ice::Ice(const Ice &toCopy) : AMateria(toCopy) {
	cout << "Ice: Copy constructor called" << endl;
}

Ice* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &target) const {
	cout << "* shoots and ice bolt at " << target.getName() << " *" << endl;
}