#include "Harl.hpp"

int	main(int ac, char **av) {
	Harl noHarl;

	switch (ac) {
		case 2:
			noHarl.complain(av[1]);
			break;
		default:
			cout << "Input correct amount of arguments!" << endl;
			return 1;
	}
	return 0;
}