#include "easyfind.tpp"
#include "easyfind.hpp"

int	main( void ) {
	std::vector<int> numbers;
	for (int i = 0; i < 10; ++i)
		numbers.push_back(i);
	try {
		easyfind(numbers, 4);
		easyfind(numbers, 11);
	}
	catch (std::exception &except) {
		cout << except.what() << endl;
	}
	return 0;
}