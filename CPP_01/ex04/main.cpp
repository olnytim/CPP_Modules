#include "MiniSed.hpp"

int	main(int ac, char **av) {
	if (ac != 4) {
		cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << endl;
		return 1;
	}

	MiniSed a(av[1], av[2], av[3]);


	return 0;
}