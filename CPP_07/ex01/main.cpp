#include "iter.hpp"

int main(void) {
	int	array[] = {0, 0, 0, 1};
	cout << "Start: " << endl;
	::iter(array, sizeof(array) / sizeof(array[0]), ::print_element<int>);

	cout << "*Increment*" << endl;
	::iter(array, sizeof(array) / sizeof(array[0]), ::increment<int>);

	cout << "Finish: " << endl;
	::iter(array, sizeof(array) / sizeof(array[0]), ::print_element<int>);
	return 0;
}