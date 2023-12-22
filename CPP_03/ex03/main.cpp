#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {


	DiamondTrap e("lol");
	std::cout << std::endl;

	e.whoAmI();
	std::cout << std::endl;
	std::cout << e.getHealth() << std::endl;
	std::cout << e.getEnergy() << std::endl;
	std::cout << e.getAttack() << std::endl;

	return 0;
}