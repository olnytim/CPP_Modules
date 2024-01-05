#include "ClapTrap.hpp"

int main() {

	ClapTrap a("Luffy");
	cout << endl;

	ClapTrap b("Ussop");
	cout << endl;

	a.attack(b.getName());
	a.takeDamage(b.getAttack());
	a.beRepaired(7);
	cout << endl;

	b.attack(a.getName());
	b.takeDamage(a.getAttack());
	b.beRepaired(5);
	cout << endl;

	return 0;
}