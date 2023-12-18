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
};

#endif