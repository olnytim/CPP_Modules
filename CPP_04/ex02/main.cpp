#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {

	const Animal* i = new Cat();
	const Animal* j = new Dog();

	cout << endl;

	delete i;
	delete j;

	cout << endl;

	Dog p;
	{
		Dog a = p;
	}

	cout << endl;

	const Animal *arr[4];

	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		switch (i) {
			case 0:		arr[i] = new Dog();
			case 1:		arr[i] = new Dog();
			default:	arr[i] = new Cat();
		}
	}

	cout << endl;

	for (int i = 0; i < 4; i++)
		delete arr[i];

	return 0;
}