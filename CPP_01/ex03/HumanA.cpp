#include "HumanA.hpp"

HumanA::HumanA(string humanName, Weapon weaponType) : _name(humanName), weapon(weaponType) {}
HumanA::~HumanA() {}

void HumanA::attack() {
	cout << _name << " attacks with their " << weapon.getType() << endl;
}