#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void) {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	cout << std::endl;

	cout << j->getType() << " " << endl;
	cout << i->getType() << " " << endl;

	cout << endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	cout << endl;

	delete meta;
	delete j;
	delete i;

	cout << endl;

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* j2 = new WrongCat();

	cout << endl;

	cout << meta2->getType() << endl;
	cout << j2->getType() << endl;

	cout << endl;

	meta2->makeSound();
	j2->makeSound();

	cout << endl;

	delete meta2;
	delete j2;

	return 0;;
}