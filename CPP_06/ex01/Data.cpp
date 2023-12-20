#include "Data.hpp"

int	Data::getDataValue() const {
	return dataValue;
}

Data::Data() : dataValue(0) {}

Data::Data( int value ) : dataValue(value) {}

Data::Data(const Data &toCopy) {
	Data::operator=(toCopy);
}

Data &Data::operator=(const Data &toCopy) {
	dataValue = toCopy.dataValue;
}

Data::~Data() {}