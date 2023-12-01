#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	cout << "ScavTrap: Default constructor called" << endl;
	setName("NoName");
	setAttack(20);
	setEnergy(50);
	setHealth(100);
}

ScavTrap::~ScavTrap() {
	cout << "ScavTrap: Destructor called" << endl;
}

ScavTrap::ScavTrap(string name) {
	cout << "ScavTrap: Name constructor called" << endl;
	setName(name);
	setAttack(20);
	setEnergy(50);
	setHealth(100);
}

ScavTrap& ScavTrap::operator=(const ScavTrap &toCopy) {
	cout << "ScavTrap: Copy assignment operator called" << endl;
	setName(toCopy.getName());
	setAttack(toCopy.getAttack());
	setEnergy(toCopy.getEnergy());
	setHealth(toCopy.getHealth());
	return *this;
}

ScavTrap::ScavTrap(const ScavTrap &toCopy) {
	cout << "ScavTrap: Copy constructor called" << endl;
	*this = toCopy;
}

void ScavTrap::guardGate() {
	cout << "ScavTrap " << getName() << " is now in Gate keeper mode!" << endl;
}

void ScavTrap::attack(const string &target) {
	if (getHealth() > 0 && getEnergy() > 0) {
		cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttack() << " points of damage!" << endl;
		setEnergy(getEnergy() - 1);
	}
	else { cout << "ScavTrap " << getName() << " can't do this!" << endl; }
}