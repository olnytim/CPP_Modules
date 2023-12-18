#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

class C : public Base {
public:
	C();
	C( const C &toCopy );
	C &operator=( const C &toCopy );
	~C();

};

#endif