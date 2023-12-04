#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain {
private:
	string	ideas[100];

public:
	Brain();
	~Brain();
	Brain &operator=( const Brain &toCopy );
	Brain( const Brain &toCopy );

	string	getIdea( int i ) const;
	void	setIdea( int i, string idea );
};

#endif