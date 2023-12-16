#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

class ScalarConverter {
private:

public:
	ScalarConverter();
	ScalarConverter( const ScalarConverter &toCopy );
	ScalarConverter &operator=( const ScalarConverter &toCopy );
	~ScalarConverter();
};

#endif