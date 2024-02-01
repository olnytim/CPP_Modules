#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat bureaucrat("John", 1);
		cout << bureaucrat ;
		try
		{
			bureaucrat.incrementGrade();
		}
		catch (exception &e)
		{
			cout << e.what() << endl;
		}
		try
		{
			bureaucrat.decrementGrade();
		}
		catch(const exception &e)
		{
			cout << e.what() << endl;
		}
		cout << bureaucrat ;
		return 0;
	}
	catch (const exception &e) {
		cout << e.what() << endl;
	}
}