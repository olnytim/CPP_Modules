#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
	ClapTrap a("General Kenobi");
	ClapTrap b(a);
	a.attack("General Grievous");
	a.setAttack(5);
	a.attack("General Grievous");
	a.takeDamage(9);
	a.beRepaired(3);

	ScavTrap hi;
	hi.setHealth(20);
	hi.takeDamage(19);
	hi.getName();
	hi.attack("General Kenobi");

	FragTrap c("Leon");
	return (0);
}