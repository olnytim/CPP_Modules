#include "ClapTrap.hpp"

int main() {

	ClapTrap a("Luffy");
	std::cout << std::endl;

	ClapTrap b("Ussop");
	std::cout << std::endl;

	a.attack(b.getName());
	a.takeDamage(b.getAttack());
	a.beRepaired(7);
	std::cout << std::endl;

	b.attack(a.getName());
	b.takeDamage(a.getAttack());
	b.beRepaired(5);
	std::cout << std::endl;

	return 0;
}