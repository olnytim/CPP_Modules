#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(string name) : _name(name) {}

void	Zombie::announce(void) {
	cout<< _name << ": BraiiiiiiinnnzzzZ..." << endl;
}

Zombie::~Zombie(void) {
	cout << _name << " has been destroyed." << endl;
}

void Zombie::setName(string name) {
	_name = name;
}