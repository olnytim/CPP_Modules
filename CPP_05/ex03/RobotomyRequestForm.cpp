#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const string &target) : AForm("RobotomyRequestForm", 72, 45) {
	setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &toCopy) : AForm(toCopy) {
	*this = toCopy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &toCopy) {
	if (this != &toCopy)
		AForm::operator=(toCopy);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (getSigned() == "false")
		throw AForm::FormNotSignedException();
	cout << getTarget() << "* drilling noise *" << endl;
	if (!(rand() % 2))
		cout << getTarget() << " has been robotomized successfully!" << endl;
	else
		cout << getTarget() << " the robotomy failed:(" << endl;
}