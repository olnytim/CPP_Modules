#include "Zombie.hpp"

Zombie	*zombieHorde(int N, string name) {
	Zombie *Horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		Horde[i] = Zombie(name);
	}
	return Horde;
}