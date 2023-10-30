#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {

private:
	string	_name;
	Weapon	weapon;

public:
	HumanA(string humanName, Weapon weaponType);
	~HumanA();
	void	attack(void);
};

#endif