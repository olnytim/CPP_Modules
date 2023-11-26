#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap a("General Kenobi");
	ClapTrap b(a);
	a.attack("General Grievous");
	a.setAttack(5);
	a.attack("General Grievous");
	a.takeDamage(9);
	a.beRepaired(3);
	return (0);
}