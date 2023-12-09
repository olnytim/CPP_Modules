#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(string const &name, int grade) : _name(name), _grade(grade) {}

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

string const	&Bureaucrat::getName() const {
	return _name;
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &toShow) {
	out << toShow.getName() << ", bureaucrat grade " << toShow.getGrade() << endl;
	return out;
}

void	Bureaucrat::decrementGrade() {

}

void	Bureaucrat::incrementGrade() {
	
}