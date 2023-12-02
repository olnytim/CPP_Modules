#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	~Cat();
	Cat( const Cat &toCopy );
	Cat &operator=( const Cat &toCopy );

	virtual void	makeSound( void ) const;
};

#endif