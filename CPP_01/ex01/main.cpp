#include "Zombie.hpp"

int	main(void) {
	int N;
	cout << "Enter number of zombies: ";
	cin >> N;
	string name;
	cout << "Enter name for HORDE OF ZOMBIE: ";
	cin >> name;
	if (N >= 0 && N < INT_MAX) {
		Zombie *horde = zombieHorde(N, name);
		for (int i = 0; i < N; i++) {
			horde[i].announce();
		}

		delete [] horde;
	}
	else {
		cout << "Use valid number of zombies!" << endl;
		return 1;
	}

	return 0;
}