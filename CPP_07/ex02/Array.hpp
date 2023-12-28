#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

class Array {
private:

public:
	Array();
	Array( const Array &toCopy );
	Array &operator=( const Array &toCopy );
	~Array();
};

#endif
