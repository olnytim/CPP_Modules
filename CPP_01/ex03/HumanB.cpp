#include "HumanB.hpp"

HumanB::HumanB(string humanName) : _name(humanName), weapon(nullptr) {}
HumanB::~HumanB() {}

void HumanB::attack() {
	if (weapon) {
		cout << _name << " attacks with their " << weapon->getType() << endl;
	}
	else {
		cout << _name << " attacks with their hands " << endl;
	}
}

void HumanB::setWeapon(Weapon newWeapon) {
	weapon = &newWeapon;
}