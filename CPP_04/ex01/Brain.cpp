#include "Brain.hpp"

Brain::Brain() {
	cout << "Brain: " << "Default constructor called" << endl;
}

Brain::~Brain() {
	cout << "Brain: " << "Default destructor called" << endl;
}

Brain& Brain::operator=(const Brain &toCopy) {
	cout << "Brain: " << "Copy assignment operator called" << endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = toCopy.ideas[i];
	}
	return *this;
}

Brain::Brain(const Brain &toCopy) {
	cout << "Brain: " << "Copy constructor called" << endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = toCopy.ideas[i];
	}
}