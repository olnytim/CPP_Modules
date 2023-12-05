#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
	Cure();
	~Cure();
	Cure( const Cure &toCopy );
	Cure &operator=( const Cure &toCopy );

	Cure	*clone() const;
	void	use( ICharacter &target ) const;
};

#endif