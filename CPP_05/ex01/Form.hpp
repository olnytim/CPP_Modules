#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

using std::string;

class Bureaucrat;

class Form {
private:
	const string	_name;
	const int	_gradeToSign;
	const int	_gradeToExecute;
	bool	_signed;

public:
	Form();
	Form( const string &name, int gradeToSign);
	Form( const string &name, int gradeToSign, int gradeToExecute);
	Form( const Form &toCopy );
	Form &operator=( const Form &toCopy );
	~Form();

	int	getGradeToExecute( void ) const ;
	int	getGradeToSign( void ) const ;
	const string	&getName( void ) const ;
	string	getSigned( void ) const ;

	void	beSigned( const Bureaucrat &toCheck );

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<( std::ostream &out, const Form &toShow );

#endif