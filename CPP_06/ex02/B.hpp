#ifndef B_HPP
#define B_HPP

#include "Base.hpp"

class B : public Base {
public:
	B();
	B( const B &toCopy );
	B &operator=( const B &toCopy );
	~B();

};

#endif