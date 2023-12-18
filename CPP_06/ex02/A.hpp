#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A : public Base {
public:
	A();
	A( const A &toCopy );
	A &operator=( const A &toCopy );
	~A();
};

#endif