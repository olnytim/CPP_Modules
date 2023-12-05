#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;
using	std::vector;

class AMateria {
protected:
	string	type;

public:
	AMateria( string const &type );
	AMateria();
	virtual ~AMateria();
	AMateria( const AMateria &toCopy );
	AMateria &operator=( const AMateria &toCopy );

	string &getType( void ) const;

	virtual AMateria	*clone( void ) const = 0;
	virtual void	use( ICharacter &target );
};

#endif