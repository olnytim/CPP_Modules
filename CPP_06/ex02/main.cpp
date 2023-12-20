#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void) {
	Base *c;
	c = generate();
	identify(c);
	identify(*c);
	delete c;
}