#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource {
protected:


public:
	virtual	~IMateriaSource();
	IMateriaSource( const IMateriaSource &toCopy );
	IMateriaSource();
	IMateriaSource &operator=( const IMateriaSource &toCopy );

	virtual void	learnMateria(AMateria*) = 0;
	virtual AMateria*	createMateria(std::string const & type) = 0;
};

#endif