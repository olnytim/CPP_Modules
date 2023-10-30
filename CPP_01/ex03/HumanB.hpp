#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {

private:
	string	_name;
	Weapon	*weapon;

public:
	HumanB(string humanName);
	~HumanB();

	void	setWeapon(Weapon *newWeapon);
	void	attack(void);
};

#endif