#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Weapon {
private:
	string	_type;

public:
	Weapon(const string weaponName);
	~Weapon();
	const string	&getType(void) const;
	void	setType(const string weaponType);
};

#endif