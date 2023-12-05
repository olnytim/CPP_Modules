#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
public:
	Ice();
	~Ice();
	Ice( const Ice &toCopy );
	Ice &operator=( const Ice &toCopy );

	Ice	*clone() const;
	void	use( ICharacter &target ) const;
};

#endif