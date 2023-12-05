#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
private:
	vector<AMateria *> learnedMaterias;

public:
	MateriaSource();
	~MateriaSource();
	MateriaSource( const MateriaSource &toCopy );
	MateriaSource &operator=( const MateriaSource &toCopy );

	void	learnMateria( AMateria* m );
	AMateria	*createMateria( string const &type );
};

#endif