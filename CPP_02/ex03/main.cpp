#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
	Point A(0, 0);
	Point B(4, 0);
	Point C(2, 3);
	Point P1(2, 2);  // Inside the triangle
	Point P2(5, 5);  // Outside the triangle

	if (bsp(A, B, C, P1)) {
		std::cout << "Point P1 is inside the triangle." << std::endl;
	} else {
		std::cout << "Point P1 is outside the triangle." << std::endl;
	}

	if (bsp(A, B, C, P2)) {
		std::cout << "Point P2 is inside the triangle." << std::endl;
	} else {
		std::cout << "Point P2 is outside the triangle." << std::endl;
	}

	return 0;
}