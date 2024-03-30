#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

using std::string;
using std::endl;
using std::cout;

class ClapTrap {
protected:
	string	_name;
	int		_health;
	int		_energy;
	int		_attack;
public:
	ClapTrap();
	ClapTrap( string name );
	ClapTrap( const ClapTrap &toCopy );
	ClapTrap &operator=( const ClapTrap &toCopy );
	~ClapTrap();

	void	attack( const string &target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );
	string	getName( void ) const;
	int		getHealth( void ) const;
	int		getEnergy( void ) const;
	int		getAttack( void ) const;
	void	setName( string name );
	void	setHealth( int amount );
	void	setEnergy( int amount );
	void	setAttack( int amount );
};

#endif
