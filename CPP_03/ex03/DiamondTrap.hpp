#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	string	_name;

public:
	DiamondTrap();
	~DiamondTrap();
	DiamondTrap( string name );
	DiamondTrap( const DiamondTrap &toCopy );
	DiamondTrap &operator=( const DiamondTrap &toCopy );

	void	whoAmI( void );
	void	attack( const string &target );
};

#endif
