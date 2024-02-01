#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

using std::string;
using std::endl;
using std::cout;

class WrongAnimal {
protected:
	string	_type;

public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal( const WrongAnimal &toCopy );
	WrongAnimal &operator=( const WrongAnimal &toCopy );

	virtual void	makeSound( void ) const;
	void			setType( string const Type );
	string			getType( void ) const;
};

#endif