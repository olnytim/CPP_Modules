#include "Character.hpp"

Character::Character() : name("NoName") {
	cout << "Character: Default constructor called" << endl;
	for (int i = 0; i < 4; ++i) {
		inventory[i] = NULL;
	}
}

Character::Character(string name) : name(name) {
	cout << "Character: Name constructor called" << endl;
}

Character& Character::operator=(const Character &toCopy) {
	cout << "Character: Copy assignment operator called" << endl;
	if (this != &toCopy) {
		this->name = toCopy.name;
		for (int i = 0; i < 4; ++i) {
			if (inventory[i]) {
				delete inventory[i];
				this->inventory[i] = NULL;
			}
			inventory[i] = toCopy.inventory[i]->clone();
		}
	}
	return (*this);
}

Character::Character(const Character &toCopy) : name(toCopy.name){
	cout << "Character: Copy constructor called" << endl;
	for (int i = 0; i < 4; ++i) {
		inventory[i] = NULL;
	}
	*this = toCopy;
}

Character::~Character() {
	cout << "Character: Destructor called" << endl;
	for (int i = 0; i < 4; ++i)
		if (inventory[i])
			delete inventory[i];
}

const string & Character::getName() const {
	return this->name;
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; ++i) {
		if (!inventory[i]) {
			inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx]->use(target);
}