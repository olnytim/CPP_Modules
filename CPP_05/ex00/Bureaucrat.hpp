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
	const string	_name;
	int	_grade;

public:
	Bureaucrat();
	Bureaucrat( string const &name, int grade );
	Bureaucrat( const Bureaucrat &toCopy );
	Bureaucrat &operator =( const Bureaucrat &toCopy );
	virtual ~Bureaucrat();

	const string	&getName( void ) const;
	int		getGrade( void ) const;
	void	incrementGrade( void );
	void	decrementGrade( void );

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<( std::ostream &out, const Bureaucrat &toShow );

#endif