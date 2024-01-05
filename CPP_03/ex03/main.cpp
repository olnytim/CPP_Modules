#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	DiamondTrap e("lol");

	e.whoAmI();
	cout << endl;
	cout << e.getHealth() << endl;
	cout << e.getEnergy() << endl;
	cout << e.getAttack() << endl;

	return 0;
}