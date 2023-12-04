#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	Brain	*_brain;
public:
	Dog();
	~Dog();
	Dog( const Dog &toCopy );
	Dog &operator=( const Dog &toCopy );

	virtual void	makeSound( void ) const;
};


#endif