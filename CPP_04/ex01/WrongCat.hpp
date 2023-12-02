#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal {
private:
	Brain	*_brain;
public:
	WrongCat();
	~WrongCat();
	WrongCat( const WrongCat &toCopy );
	WrongCat &operator=( const WrongCat &toCopy );

	virtual void	makeSound( void ) const;
};

#endif