#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

	ClapTrap a("Luffy");
	cout << endl;

	ClapTrap b("Ussop");
	cout << endl;

	ScavTrap c("Sanji");
	cout << endl;

	FragTrap d("Zoro");
	cout << endl;

	a.attack(b.getName());
	a.takeDamage(b.getAttack());
	a.beRepaired(7);
	cout << endl;

	b.attack(a.getName());
	b.takeDamage(a.getAttack());
	b.beRepaired(5);
	cout << endl;

	c.attack(a.getName());
	c.takeDamage(a.getAttack());
	c.beRepaired(10);
	c.guardGate();
	cout << endl;

	d.attack(c.getName());
	d.takeDamage(c.getAttack());
	d.beRepaired(10);
	d.highFivesGuys();
	cout << endl;

	return 0;
}