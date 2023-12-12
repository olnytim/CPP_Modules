#include "AForm.hpp"

AForm::AForm() : _name("AForm"), _gradeToSign(150), _gradeToExecute(150) {
	_signed = false;
}

AForm::AForm(const string &name, int gradeToSign) : _name(name), _gradeToSign(gradeToSign),_gradeToExecute(150) {
	if (gradeToSign > 150)
		throw AForm::GradeTooLowException();
	else if (gradeToSign < 1)
		throw AForm::GradeTooHighException();
	_signed = false;
}

AForm::AForm(const string &name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	_signed = false;
}

AForm& AForm::operator=(const AForm &toCopy) {
	if (this != &toCopy) {
		_signed = toCopy._signed;
	}
	return (*this);
}

AForm::AForm(const AForm &toCopy) : _name(toCopy.getName()), _gradeToSign(toCopy.getGradeToSign()), _gradeToExecute(toCopy.getGradeToExecute()) {
	AForm::operator=(toCopy);
}

AForm::~AForm() {}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

const string & AForm::getName() const {
	return _name;
}

string AForm::getSigned() const {
	return _signed ? "true" : "false";
}

void AForm::beSigned(const Bureaucrat &toCheck) {
	if (toCheck.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("Form not signed");
}

std::ostream &operator<<( std::ostream &out, const AForm &toShow ) {
	out << "AForm name -> "<< toShow.getName() << "\nGrade to sign -> " << toShow.getGradeToSign() << "\nGrade to execute -> " << toShow.getGradeToExecute() << "\nAForm is singed -> " << toShow.getSigned();
	return out;
}

const string	&AForm::getTarget() const {
	return _target;
}

void	AForm::setTarget(const string &target) {
	_target = target;
}