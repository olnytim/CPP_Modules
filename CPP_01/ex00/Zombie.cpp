#include "Zombie.hpp"

Zombie::Zombie(string name) : _name(name) {
	Zombie::announce();
}

void	Zombie::announce(void) {
	cout << _name << ": BraiiiiiiinnnzzzZ..." << endl;
}

Zombie::~Zombie(void) {
	cout << _name << " has been destroyed." << endl;
}