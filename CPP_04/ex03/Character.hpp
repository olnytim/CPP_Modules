#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
private:
	string	name;
	AMateria* inventory[4];

public:
	Character();
	~Character();
	Character( string name );
	Character( const Character &toCopy );
	Character &operator=( const Character &toCopy );

	string const	&getName( void ) const;
	void	equip( AMateria *m );
	void	unequip( int idx );
	void	use( int idx, ICharacter &target );
};

#endif