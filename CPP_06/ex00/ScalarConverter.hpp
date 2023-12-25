#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

using std::string;
using std::cout;
using std::endl;

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter( const ScalarConverter &toCopy );
	ScalarConverter &operator=( const ScalarConverter &toCopy );
	~ScalarConverter();

	static void	convert_to_char( const string & );
	static void	convert_to_int( const string & );
	static void	convert_to_float( const string & );
	static void	convert_to_double( const string & );
	static int	check_input_type( const string &, size_t );
	static void	print_char( char );
	static void	print_int( int );
	static void	print_float( float );
	static void	print_double( double );

	enum {
		CHAR,
		INT,
		FLOAT,
		DOUBLE
	};

public:
	static void	convert( const string & );
};

#endif