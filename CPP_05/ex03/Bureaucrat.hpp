#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <fstream>

#include "AForm.hpp"

using	std::exception;
using	std::string;
using	std::cout;
using	std::endl;

class AForm;

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

	class GradeTooHighException : public exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public exception {
	public:
		virtual const char *what() const throw();
	};

	void	signForm( AForm &toShow );
	void	executeForm( const AForm &form );
};

std::ostream &operator<<( std::ostream &out, const Bureaucrat &toShow );

#endif