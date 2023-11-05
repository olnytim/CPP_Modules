#include "Weapon.hpp"

string	Weapon::getType() {
	return _type;
}

void	Weapon::setType(string newType) {
	_type = newType;
}

Weapon::Weapon(const string &weaponType) : _type(weaponType) {}
Weapon::~Weapon() {}