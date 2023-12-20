#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Serializer {
public:
	Serializer();
	Serializer( const Serializer &toCopy );
	Serializer &operator=( const Serializer &toCopy );
	~Serializer();

	static uintptr_t	serialize(Data *ptr) {
		return reinterpret_cast<uintptr_t>(ptr);
	}

	static Data*	deserialize(uintptr_t raw) {
		return reinterpret_cast<Data *>(raw);
	}
};

#endif