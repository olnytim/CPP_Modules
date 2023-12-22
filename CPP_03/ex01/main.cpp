#include "ScavTrap.hpp"

int main() {

	ClapTrap a("Luffy");
	std::cout << std::endl;

	ClapTrap b("Ussop");
	std::cout << std::endl;

	ScavTrap c;
	std::cout << std::endl;

	a.attack(b.getName());
	a.takeDamage(b.getAttack());
	a.beRepaired(7);
	std::cout << std::endl;

	b.attack(a.getName());
	b.takeDamage(a.getAttack());
	b.beRepaired(5);
	std::cout << std::endl;

	c.attack(a.getName());
	c.takeDamage(a.getAttack());
	c.beRepaired(10);
	c.guardGate();
	std::cout << std::endl;

	return 0;
}