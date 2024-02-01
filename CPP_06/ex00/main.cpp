#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		cout << "Usage: ./convert [input]" << endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
}