#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
	AMateria	*learnedMaterias[4];
	int	numLearnedMaterias;

public:
	MateriaSource();
	~MateriaSource();
	MateriaSource( const MateriaSource &toCopy );
	MateriaSource &operator=( const MateriaSource &toCopy );

	void	learnMateria( AMateria* m );
	AMateria	*createMateria( string const &type );
};

#endif