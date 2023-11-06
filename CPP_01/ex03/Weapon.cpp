#include "Weapon.hpp"

Weapon::Weapon(const string weaponName) : _type(weaponName) {}
Weapon::~Weapon() {}

const string	&Weapon::getType() const {
	return _type;
}

void	Weapon::setType(const string weaponType) {
	_type = weaponType;
}