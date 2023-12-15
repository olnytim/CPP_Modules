#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

class Intern {
private:
	AForm	*form[3];

public:
	Intern();
	Intern( const Intern &toCopy );
	Intern &operator=( const Intern &toCopy );
	~Intern();

	AForm *makeForm( const string &formName, const string &target ) const;
	class BadFormException: public exception {
	public:
		virtual const char *what() const throw();
	};
};

#endif