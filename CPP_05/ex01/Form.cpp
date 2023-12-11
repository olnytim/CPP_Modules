#include "Form.hpp"

Form::Form() : _name("Form"), _gradeToSign(150), _gradeToExecute(150) {
	_signed = false;
}

Form::Form(const string &name, int gradeToSign) : _name(name), _gradeToSign(gradeToSign),_gradeToExecute(150) {
	if (gradeToSign > 150)
		throw Form::GradeTooLowException();
	else if (gradeToSign < 1)
		throw Form::GradeTooHighException();
	_signed = false;
}

Form::Form(const string &name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	_signed = false;
}

Form& Form::operator=(const Form &toCopy) {
	if (this != &toCopy) {
		_signed = toCopy._signed;
	}
	return (*this);
}

Form::Form(const Form &toCopy) : _name(toCopy.getName()), _gradeToSign(toCopy.getGradeToSign()), _gradeToExecute(toCopy.getGradeToExecute()) {
	Form::operator=(toCopy);
}

Form::~Form() {}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

const string & Form::getName() const {
	return _name;
}

string Form::getSigned() const {
	return _signed ? "true" : "false";
}

void Form::beSigned(const Bureaucrat &toCheck) {
	if (toCheck.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

std::ostream &operator<<( std::ostream &out, const Form &toShow ) {
	out << "Form name -> "<< toShow.getName() << "\nGrade to sign -> " << toShow.getGradeToSign() << "\nGrade to execute -> " << toShow.getGradeToExecute() << "\nForm is singed -> " << toShow.getSigned();
	return out;
}