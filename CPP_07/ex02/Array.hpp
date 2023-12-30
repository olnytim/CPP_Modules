#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
//#include "Array.tpp"

template <typename T>
class Array {
private:
	T	*_array;
	unsigned int	_size;
public:
	Array();
	Array( unsigned int n );
	Array( const Array &toCopy );
	Array &operator=( const Array &toCopy );
	~Array();

	unsigned int	size( void ) const;
	T &operator[](unsigned int i);
	const T &operator[](unsigned int i) const;
    class OutOfBoundsException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

template <typename T>
std::ostream &operator<<( std:: ostream &out, const Array<T> &array );

#endif
