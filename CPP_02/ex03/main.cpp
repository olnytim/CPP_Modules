#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
	Point A(0, 0);
	Point B(4, 0);
	Point C(2, 3);
	Point P1(2, 2);
	Point P2(5, 5);

	if (bsp(A, B, C, P1))
		cout << "Point P1 is inside the triangle." << endl;
	else
		cout << "Point P1 is outside the triangle." << endl;

	if (bsp(A, B, C, P2))
		cout << "Point P2 is inside the triangle." << endl;
	else
		cout << "Point P2 is outside the triangle." << endl;

	return 0;
}