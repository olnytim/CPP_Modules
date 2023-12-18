#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class ScalarConverter {
private:

public:
	ScalarConverter();
	ScalarConverter( const ScalarConverter &toCopy );
	ScalarConverter &operator=( const ScalarConverter &toCopy );
	~ScalarConverter();
};

#endif