#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void) {
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	cout << std::endl;

	cout << dog->getType() << endl;
	cout << cat->getType() << endl;

	cout << endl;

	cat->makeSound();
	dog->makeSound();
	animal->makeSound();

	cout << endl;

	delete animal;
	delete dog;
	delete cat;

	cout << endl;

	const WrongAnimal* animal2 = new WrongAnimal();
	const WrongAnimal* cat2 = new WrongCat();

	cout << endl;

	cout << animal2->getType() << endl;
	cout << cat2->getType() << endl;

	cout << endl;

	animal2->makeSound();
	cat2->makeSound();

	cout << endl;

	delete animal2;
	delete cat2;

	return 0;;
}