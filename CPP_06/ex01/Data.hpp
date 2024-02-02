#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <cstdint>

class Data {
private:
	int	dataValue;
public:
	Data();
	Data( int value );
	Data( const Data &toCopy );
	Data &operator=( const Data &toCopy );
	~Data();

	int	getDataValue() const;
};

#endif