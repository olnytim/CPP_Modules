#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

using std::string;
using std::endl;
using std::cout;

class Animal {
protected:
	string	_type;

public:
	Animal();
	virtual ~Animal();
	Animal( const Animal &toCopy );
	Animal &operator=(const Animal &toCopy );

	virtual void	makeSound( void ) const;
	void			setType( const string Type );
	string			getType( void ) const;
};


#endif