#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	Bureaucrat bureaucrat("Kenny", 1);
	cout << bureaucrat ;
	try
	{
		bureaucrat.incrementGrade();
	}
	catch (exception &except)
	{
		cout << except.what() << endl;
	}
	try
	{
		bureaucrat.decrementGrade();
	}
	catch(const exception& except)
	{
		cout << except.what() << endl;
	}
	cout << bureaucrat ;

	try {
		Bureaucrat bureaucrat("kek", 12);
		Form form("mda", 15);

		bureaucrat.signForm(form);

		cout << form << endl;
	}
	catch (exception &except) {
		cout << except.what() << endl;
	}
	return 0;
}