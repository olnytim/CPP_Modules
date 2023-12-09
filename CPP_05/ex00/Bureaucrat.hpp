#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

using	std::exception;
using	std::string;
using	std::cout;
using	std::endl;

class Bureaucrat {
private:
	string const	_name;
	int	_grade;

public:
	Bureaucrat();
	Bureaucrat( string const &name, int grade );
	Bureaucrat( const Bureaucrat &toCopy );
	Bureaucrat &operator =( const Bureaucrat &toCopy );
	virtual ~Bureaucrat();

	string const	&getName( void ) const;
	int		getGrade( void ) const;
	void	incrementGrade( void );
	void	decrementGrade( void );
};

std::ostream &operator<<( std::ostream &out, const Bureaucrat &toShow );

#endif