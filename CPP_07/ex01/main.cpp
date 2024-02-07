#include "iter.hpp"

class Awesome
{
public:
	Awesome ( void ) : _n( 42 ) { return; }
	int get(void) const { return this->_n; }
private:
	int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

int main() {
	int tab[] = {0, 1, 2, 3, 4 };
	Awesome tab2[5];
	iter( tab, 5, print);
	iter( tab2, 5, print);
	return 0;
}

//int main(void) {
//	double	array[] = {0, 0, 0, 1};
//	cout << "Start: " << endl;
//	::iter(array, sizeof(array) / sizeof(array[0]), ::print_element<const int>);
//
//	cout << "*Increment*" << endl;
//	::iter(array, sizeof(array) / sizeof(array[0]), ::increment<double>);
//
//	cout << "Finish: " << endl;
//	::iter(array, sizeof(array) / sizeof(array[0]), ::print_element<const int>);
//	return 0;
//}