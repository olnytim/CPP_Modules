#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base	*generate() {
	srand(time(NULL));
	char c = "ABC"[rand() % 3];
	switch (c)
	{
		case 'A': return new A;
		case 'B': return new B;
		case 'C': return new C;
	}
	return NULL;
}

void	identify( Base *p ) {
	bool	type_casted;
	if ((type_casted = dynamic_cast<A *>(p))) {
		cout << "Object identified as *A" << endl;
	}
	else if ((type_casted = dynamic_cast<B *>(p))) {
		cout << "Object identified as *B" << endl;
	}
	else if ((type_casted = dynamic_cast<C *>(p))) {
		cout << "Object identified as *C" << endl;
	}
	else
		cout << "Object isn't identified" << endl;
}

void	identify( Base &p ) {
	try {
		A &a = dynamic_cast<A &>(p);
		cout << "Object identified as &A" << endl;
		(void)a;
	}
	catch (const exception &except) {}
	try {
		B &a = dynamic_cast<B &>(p);
		cout << "Object identified as &B" << endl;
		(void)a;
	}
	catch (const exception &except) {}
	try {
		C &a = dynamic_cast<C &>(p);
		cout << "Object identified as &C" << endl;
		(void)a;
	}
	catch (const exception &except) {}
}