#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern	&Intern::operator=(const Intern &toCopy) {
	(void)toCopy;
	return *this;
}

Intern::Intern(const Intern &toCopy) {
	(void)toCopy;
}

AForm	*Intern::makeForm(const string &formName, const string &target) const {
	
}

const char	*Intern::BadFormException::what() const throw() {

}