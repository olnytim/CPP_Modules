#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>

using std::endl;
using std::cout;
using std::exception;

class Base {
public:
	virtual ~Base();
};

Base	*generate( void );
void	identify( Base *p );
void	identify( Base &p );

#endif