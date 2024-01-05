#include "MiniSed.hpp"

MiniSed::MiniSed(char *filename, char *s1, char *s2) {
	_s1 = s1;
	_s2 = s2;
	_filename = filename;
}

MiniSed::~MiniSed() {}

void MiniSed::openSourceFile(string filename) {
	inputFile.open(filename);
	if (!inputFile) {
		cerr << "Error opening file!" << endl;
		exit(1);
	}
	string line;
	while (std::getline(inputFile, line, '\0')) {}
	if (line.empty()) {
		cout << "Empty file!" << endl;
		exit(1);
	}
	inputFile.close();
	inputFile.open(filename);
}

void MiniSed::createNewFile() {
	outputFile.open(_filename + ".replace");
	if (!outputFile) {
		cerr << "Error opening new file!" << endl;
		exit(1);
	}
}

void MiniSed::readReplace() {
	string line;
	while (std::getline(inputFile, line)) {
		string	newLine;
		size_t	pos = 0;
		while (pos < line.length()) {
			size_t	found = line.find(_s1, pos);
			if (found == string::npos) {
				newLine += line.substr(pos);
				break;
			} else {
				newLine += line.substr(pos, found - pos);
				newLine += _s2;
				pos = found + _s1.length();
			}
		}
		outputFile << newLine << "\n";
	}
	inputFile.close();
	outputFile.close();
}

string MiniSed::getFilename() {
	return _filename;
}
