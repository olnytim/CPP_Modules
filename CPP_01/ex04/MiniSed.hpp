#include <iostream>
#include <fstream>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class MiniSed {
private:
	string	_filename;
	string	_s1;
	string	_s2;
	std::ifstream inputFile;
	std::ofstream outputFile;

public:
	MiniSed(char *filename, char *s1, char *s2);
	~MiniSed();
	void	openSourceFile(string filename);
	void	createNewFile(void);
	void	readReplace(void);
	string	getFilename(void);
};