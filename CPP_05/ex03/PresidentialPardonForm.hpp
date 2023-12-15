#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm();
	PresidentialPardonForm( const string &target );
	PresidentialPardonForm( const PresidentialPardonForm &toCopy );
	PresidentialPardonForm &operator=( const PresidentialPardonForm &toCopy );
	virtual ~PresidentialPardonForm();

	void	execute( const Bureaucrat &executor ) const;
	AForm *clone( const string &target );
	class OpenFileException : public exception {
	public:
		virtual const char *what() const throw();
	};
};

#endif