#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const string &target) : AForm("PresidentialPardonForm", 25, 5) {
	setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &toCopy) : AForm(toCopy) {
	*this = toCopy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &toCopy) {
	if (this != &toCopy)
		AForm::operator=(toCopy);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const char* PresidentialPardonForm::OpenFileException::what() const throw() {
	return ("File was not opened!");
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (getSigned() == "false")
		throw AForm::FormNotSignedException();
	cout << getTarget() << " has been pardoned by Zaphod Beeblerox." << endl;
}

AForm* PresidentialPardonForm::clone(const string &target) {
	AForm *temp = new PresidentialPardonForm(target);
	return temp;
}