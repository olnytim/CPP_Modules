#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

#include "ICharacter.hpp"

using	std::string;
using	std::cout;
using	std::endl;

class ICharacter;

class AMateria {
protected:
	string	type;

public:
	AMateria( string const &type );
	AMateria();
	virtual ~AMateria();
	AMateria( const AMateria &toCopy );
	AMateria &operator=( const AMateria &toCopy );

	string const &getType( void ) const;

	virtual AMateria	*clone( void ) const = 0;
	virtual void	use( ICharacter &target );
};

#endif