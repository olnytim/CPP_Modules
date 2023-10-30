#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <limits.h>

using std::cout;
using std::cin;
using std::string;
using std::endl;

class Zombie {

private:
	string	_name;

public:
	Zombie();
	Zombie(string name);
	~Zombie(void);
	void	announce(void);
};

Zombie	*zombieHorde(int N, string name);

#endif