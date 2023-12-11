#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(string const &name, int grade) : _name(name) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw  Bureaucrat::GradeTooHighException();
	_grade = grade;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &toCopy) {
	if (this != &toCopy)
		_grade = toCopy._grade;
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &toCopy) {
	*this = toCopy;
}

Bureaucrat::~Bureaucrat() {}

int	Bureaucrat::getGrade() const {
	return _grade;
}

const string	&Bureaucrat::getName() const {
	return _name;
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &toShow) {
	out << toShow.getName() << ", bureaucrat grade " << toShow.getGrade() << endl;
	return out;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

void	Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form &toShow) {
	try {
		toShow.beSigned(*this);
		cout << getName() << " signed " << toShow.getName() << endl;
	}
	catch (exception &except){
		cout << getName() << " couldn't sign " << toShow.getName() << " because " << except.what() << "." << endl;
	}
}