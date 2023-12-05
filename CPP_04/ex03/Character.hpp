#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"

class Character : public ICharacter {
private:
	string	name;
	vector<AMateria*> inventory;

public:
	Character();
	~Character();
	Character( const Character &toCopy );
	Character &operator=( const Character &toCopy );

	const string	&getName( void ) const;
	void	equip( AMateria *m );
	void	unequip( int idx );
	void	use( int i, ICharacter &target );
};

#endif