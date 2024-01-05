#include "Zombie.hpp"

Zombie	*newZombie(string name);
void	randomChump(string name);

int	main(void) {
	string name1;
	cout << "Enter stack zombie name: ";
	cin >> name1;
	Zombie stackZombie(name1);

	string name2;
	cout << "Enter heap zombie name: ";
	cin >> name2;
	Zombie *heapZombie = newZombie(name2);

	string name3;
	cout << "Enter random zombie name: ";
	cin >> name3;
	randomChump(name3);

	delete heapZombie;

	return 0;
}