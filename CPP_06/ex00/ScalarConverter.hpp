#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;

enum {
	NAN_INF,
	ERROR,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter( ScalarConverter const &other );
	ScalarConverter &operator=( ScalarConverter const &other );
	~ScalarConverter();

public:
	static void convert( string const &input );
};

#endif