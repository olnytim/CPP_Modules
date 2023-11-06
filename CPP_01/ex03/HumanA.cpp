#include "HumanA.hpp"

HumanA::HumanA(const string &humanName, Weapon &weaponType) : _weapon(weaponType) {
	_name = humanName;
}
HumanA::~HumanA() {}

void HumanA::attack() {
	cout << _name << " attacks with their " << _weapon.getType() << endl;
}