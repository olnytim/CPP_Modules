#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm( const string &target );
	ShrubberyCreationForm( const ShrubberyCreationForm &toCopy );
	ShrubberyCreationForm &operator= (const ShrubberyCreationForm &toCopy );
	~ShrubberyCreationForm();

	void	execute( const Bureaucrat &executor ) const;
	class OpenFileException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

#endif