#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

	ClapTrap a("Luffy");
	std::cout << std::endl;

	ClapTrap b("Ussop");
	std::cout << std::endl;

	ScavTrap c("Sanji");
	std::cout << std::endl;

	FragTrap d("Zoro");
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

	d.attack(c.getName());
	d.takeDamage(c.getAttack());
	d.beRepaired(10);
	d.highFivesGuys();
	std::cout << std::endl;

	return 0;
}