#include "MiniSed.hpp"

MiniSed::MiniSed(char *filename, char *s1, char *s2) {
	_s1 = s1;
	_s2 = s2;
	_filename = filename;
}

MiniSed::~MiniSed() {}