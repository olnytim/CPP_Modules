#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
public:
	ScavTrap();
	ScavTrap( string name );
	ScavTrap( const ScavTrap &toCopy );
	ScavTrap &operator=( const ScavTrap &toCopy );
	~ScavTrap();

	void	guardGate( void );
	void	attack( const string &target );
};

#endif