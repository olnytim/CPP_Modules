#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap( string name );
	FragTrap( const FragTrap &toCopy );
	FragTrap &operator=( const FragTrap &toCopy );
	~FragTrap();

	void	highFivesGuys( void );
};

#endif