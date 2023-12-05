#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	cout << "Cure: Default constructor called" << endl;

}

Cure::~Cure() {
	cout << "Cure: Destructor called" << endl;
}

Cure& Cure::operator=(const Cure &toCopy) {
	cout << "Cure: Copy assignment operator called" << endl;
	if (*this != toCopy) {
		*this->type = toCopy.type;
	}
	return *this;
}

Cure::Cure(const Cure &toCopy) : AMateria(toCopy) {
	cout << Cure: Copy constructor called" << endl;
}

Cure* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter &target) const {
	cout << "* heals " << target.getName() << "'s wounds *" << endl;
}