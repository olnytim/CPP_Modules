#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"

using std::string;
using std::exception;

class Bureaucrat;

class AForm {
private:
	const string	_name;
	string	_target;
	const int	_gradeToSign;
	const int	_gradeToExecute;
	bool	_signed;

public:
	AForm();
	AForm( const string &name, int gradeToSign);
	AForm( const string &name, int gradeToSign, int gradeToExecute);
	AForm( const AForm &toCopy );
	AForm &operator=( const AForm &toCopy );
	virtual ~AForm();

	virtual int	getGradeToExecute( void ) const ;
	virtual int	getGradeToSign( void ) const ;
	virtual string const	&getTarget( void ) const;
	virtual void	setTarget( const string &target );
	virtual const string	&getName( void ) const ;
	virtual string	getSigned( void ) const ;

	virtual void	beSigned( const Bureaucrat &toCheck );
	virtual void	execute( const Bureaucrat &executor ) const = 0;
	virtual AForm *clone( const string &target ) = 0;

	class GradeTooLowException : public exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooHighException : public exception {
	public:
		virtual const char *what() const throw();
	};
	class FormNotSignedException : public exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<( std::ostream &out, const AForm &toShow );

#endif