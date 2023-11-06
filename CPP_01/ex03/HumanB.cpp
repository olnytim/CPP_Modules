#include "HumanB.hpp"

HumanB::HumanB(const string humanName) : _name(humanName) {}
HumanB::~HumanB() {}

void HumanB::attack() {
	cout << _name << " attacks with their " << _weapon->getType() << endl;
}

void	HumanB::setWeapon(Weapon &weaponType) {
	_weapon = &weaponType;
}