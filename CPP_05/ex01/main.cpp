#include "Bureaucrat.hpp"

int	main(void) {
	Bureaucrat bureaucrat("John", 1);
	std::cout << bureaucrat ;
	try
	{
		bureaucrat.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		bureaucrat.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucrat ;
	return 0;
}