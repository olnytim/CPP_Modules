#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

class Zombie {

private:
	string	_name;

public:
	Zombie(string name);
	~Zombie(void);
	void	announce(void);
};

Zombie	*newZombie(string name);
void	randomChump(string name);

#endif ZOMBIE_H