#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Weapon {

private:
	string	_type;

public:
	string	getType();
	void	setType();
};

#endif