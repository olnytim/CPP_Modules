#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include "Data.hpp"

using std::cout;
using std::endl;

class Serializer {
private:
	Serializer();
	Serializer( const Serializer &toCopy );
	Serializer &operator=( const Serializer &toCopy );
	~Serializer();

public:
	static uintptr_t	serialize( Data *ptr );
	static Data	*deserialize( uintptr_t raw );
};

#endif