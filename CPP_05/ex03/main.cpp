#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void) {
	Bureaucrat John("John Wick", 2);
	cout << John;

	cout << endl;

	Bureaucrat Winston("Winston Scott", 140);
	cout << Winston;

	cout << endl;

	Bureaucrat Charon("Charon", 120);
	cout << Charon;

	cout << endl;

	AForm* Shrubbery = new ShrubberyCreationForm("Form1");
	AForm* Robotomy = new RobotomyRequestForm("Form2");
	AForm* Presidential = new PresidentialPardonForm("Form3");

	John.signForm(*Shrubbery);
	Winston.signForm(*Robotomy);
	Charon.signForm(*Presidential);

	cout << endl;

	John.executeForm(*Shrubbery);
	Winston.executeForm(*Robotomy);
	Charon.executeForm(*Presidential);

	try {
		Bureaucrat bureaucrat("ash", 2); // error with 200
		ShrubberyCreationForm form1("Shrubbery");
		RobotomyRequestForm form2("Robotomy");
		PresidentialPardonForm form3("President");

		cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << endl;
		bureaucrat.signForm(form1);
		bureaucrat.executeForm(form1);
		cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << endl;
		bureaucrat.signForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		cout << "\n--------------- Form 3 ( President ) ---------------" << endl;
		bureaucrat.signForm(form3);
		bureaucrat.executeForm(form3);
	}
	catch (exception &except) {
		cout << except.what() << endl;
	}
	{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	}
}
