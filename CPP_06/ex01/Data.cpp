#include "Data.hpp"

Data::Data() : dataValue(0) {}

Data::Data(int value) : dataValue(value) {}

Data::Data(const Data &toCopy) {
	Data::operator=(toCopy);
}

Data &Data::operator=(const Data &toCopy) {
	dataValue = toCopy.dataValue;
	return *this;
}

Data::~Data() {}

int	Data::getDataValue() const {
	return dataValue;
}
