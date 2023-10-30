#include "Zombie.hpp"

Zombie	*newZombie(string name) {
	Zombie	*newOne = new Zombie(name);
	return newOne;
}