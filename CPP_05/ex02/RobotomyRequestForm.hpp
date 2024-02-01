#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
	RobotomyRequestForm();
public:
	RobotomyRequestForm( const string &target );
	RobotomyRequestForm( const RobotomyRequestForm &toCopy );
	RobotomyRequestForm &operator=( const RobotomyRequestForm &toCopy );
	~RobotomyRequestForm();

	void	execute( const Bureaucrat &executor ) const;
};

#endif