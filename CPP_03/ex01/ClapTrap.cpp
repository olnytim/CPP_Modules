#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("NoName"), _health(10), _energy(10), _attack(0) { cout << "ClapTrap: Default constructor called" << endl; }

ClapTrap::ClapTrap(string name): _name(name), _health(10), _energy(10), _attack(0) { cout << "ClapTrap: Name constructor called" << endl; }

ClapTrap::ClapTrap(const ClapTrap &toCopy) {
	cout << "ClapTrap: Copy constructor called" << endl;
	*this = toCopy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &toCopy) {
	cout << "ClapTrap: Copy assignment operator called" << endl;
	_name = toCopy.getName();
	_health = toCopy.getHealth();
	_energy = toCopy.getEnergy();
	_attack = toCopy.getAttack();
	return *this;
}

ClapTrap::~ClapTrap() { cout << "ClapTrap: Destructor called" << endl; }

void ClapTrap::attack(const string &target) {
	if (_health > 0 && _energy > 0) {
		cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!" << endl;
		--_energy;
	}
	else { cout << "ClapTrap " << _name << " can't do this!" << endl; }
}

void ClapTrap::takeDamage(unsigned int amount) {
	_health -= amount;
	if (_health > 0) {
		cout << "ClapTrap " << _name << " is received " << amount << " damage!" << endl;
	}
	else if (_health <= 0) {
		cout << "ClapTrap " << _name << " is dead!" << endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_health > 0 && _energy > 0) {
		_health += amount;
		--_energy;
		cout << "ClapTrap " << _name << " repaired " << amount << " health!" << endl;
	}
	else { cout << "ClapTrap " << _name << " can't do this!" << endl; }
}

int ClapTrap::getAttack() const {
	return (_attack);
}

int ClapTrap::getHealth() const {
	return (_health);
}

int ClapTrap::getEnergy() const {
	return (_energy);
}

string ClapTrap::getName() const {
	return (_name);
}

void ClapTrap::setAttack(int amount) {
	_attack = amount;
}

void ClapTrap::setHealth(int amount) {
	_health = amount;
}

void ClapTrap::setEnergy(int amount) {
	_energy = amount;
}

void ClapTrap::setName(string name) {
	_name = name;
}