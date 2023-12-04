#ifndef HARL_HPP
#define HARL_HPP



using std::string;
using std::cout;
using std::endl;

class Harl {
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );

public:
	void	complain( string level );
	void	harlFilter(int i);
};

#endif