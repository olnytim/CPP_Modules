#include "Intern.hpp"

Intern::Intern() {
	form[0] = new ShrubberyCreationForm();
	form[1] = new RobotomyRequestForm();
	form[2] = new PresidentialPardonForm();
}

Intern::~Intern() {}

Intern	&Intern::operator=(const Intern &toCopy) {
	form[0] = toCopy.form[0];
	form[1] = toCopy.form[1];
	form[2] = toCopy.form[2];
	return *this;
}

Intern::Intern(const Intern &toCopy) {
	Intern::operator=(toCopy);
}

AForm	*Intern::makeForm(const string &formName, const string &target) const {
	(void)target;
	const char *formNames[3];
	formNames[0] = "shrubbery creation";
	formNames[1] = "robotomy request";
	formNames[2] = "presidential pardon";
	try {
		for (int i = 0; i < 3; ++i) {
			if (formNames[i] == formName) {
				cout << "Intern creates " << formName << endl;
				return form[i]->clone(target);
			}
		}
	}
	catch (exception &except) {
		cout << except.what() << endl;
	}
	return nullptr;
}

const char	*Intern::BadFormException::what() const throw() {
	return ("Bad form!");
}