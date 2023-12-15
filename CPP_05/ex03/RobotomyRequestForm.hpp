#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm();
	RobotomyRequestForm( const string &target );
	RobotomyRequestForm( const RobotomyRequestForm &toCopy );
	RobotomyRequestForm &operator=( const RobotomyRequestForm &toCopy );
	~RobotomyRequestForm();

	AForm *clone( const string &target );
	void	execute( const Bureaucrat &executor ) const;
	class OpenFileException : public exception {
	public:
		virtual const char *what() const throw();
	};
};

#endif