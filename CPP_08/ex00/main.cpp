#include "easyfind.hpp"

int	main( void ) {
	std::vector<int> array;
	for (int i = 0; i < 10; ++i)
		array.push_back(i);
	try {
		easyfind(array, 4);
		easyfind(array, 10);
	}
	catch (std::exception &except) {
		cout << except.what() << endl;
	}
	return 0;
}