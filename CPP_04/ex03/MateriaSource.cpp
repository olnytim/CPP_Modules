#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : numLearnedMaterias(0) {
	for (int i = 0; i < 4; ++i)
		learnedMaterias[i] = NULL;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &toCopy) {
	if (this != &toCopy) {
		for (int i = 0; i < numLearnedMaterias; ++i)
			delete learnedMaterias[i];
		numLearnedMaterias = toCopy.numLearnedMaterias;
		for (int i = 0; i < numLearnedMaterias; ++i)
			learnedMaterias[i] = toCopy.learnedMaterias[i];
	}
	return *this;
}

MateriaSource::MateriaSource(const MateriaSource &toCopy) {
	for (int i = 0; i < numLearnedMaterias; ++i) {
		learnedMaterias[i] = toCopy.learnedMaterias[i];
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i)
		delete learnedMaterias[i];
}

void MateriaSource::learnMateria(AMateria *m) {
	if (numLearnedMaterias < 4)
		learnedMaterias[numLearnedMaterias++] = m;
}

AMateria* MateriaSource::createMateria(const string &type) {
	for (int i = 0; i < numLearnedMaterias; ++i) {
		if (learnedMaterias[i]->getType() == type) {
			return learnedMaterias[i]->clone();
		}
	}
	return NULL;
}