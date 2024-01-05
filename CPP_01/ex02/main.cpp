#include <iostream>

using std::string;
using std::cout;
using std::endl;

int	main(void) {
	string var = "HI THIS IS BRAIN";
	string *stringPTR = &var;
	string &stringREF = var;

	cout << "The memory address of the string variable: " << &var << endl;
	cout << "The memory address held by stringPTR: " << &stringPTR << endl;
	cout << "The memory address held by stringREF: " << &stringREF << endl;

	cout << "The value of the string variable: " << var << endl;
	cout << "The value pointed to by stringPTR: " << *stringPTR << endl;
	cout << "The value pointed to by stringREF: " << stringREF << endl;
}