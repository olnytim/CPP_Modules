#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter( const ScalarConverter &toCopy ) {
	ScalarConverter::operator=(toCopy);
}

ScalarConverter &ScalarConverter::operator=( const ScalarConverter &toCopy) {
	(void)toCopy;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isNanInf(string const &input)
{
	return (input == "nan" || input == "nanf" || input == "inf" || input == "inff" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff");
}

static bool isSpecialChar(string const &input)
{
	return (input.length() == 1 &&	(input[0] == '+' || input[0] == '-' || input[0] == '.' || input[0] == 'f'));
}

static bool hasInvalidSignal(const string &input) {
	size_t firstSignalPos = input.find_first_of("+-");
	size_t lastSignalPos = input.find_last_of("+-");
	return (firstSignalPos != lastSignalPos);
}

static bool isInt(string const &input)
{
	return (input.find_first_not_of("+-0123456789") == string::npos);
}

static bool isDouble(string const &input)
{
	return (input.find_first_not_of("+-0123456789.") == string::npos);
}

static bool isInvalidDouble(const string &input) {
	size_t dotPos = input.find_first_of(".");
	return (dotPos != input.find_last_of(".")
			|| !std::isdigit(input[dotPos + 1]) || dotPos == 0);
}

static bool isFloat(string const &input)
{
	return (input.find_first_not_of("+-0123456789.f") == string::npos);
}

static bool isInvalidFloat(const string &input) {
	size_t dotPos = input.find_first_of(".");
	size_t fPos = input.find_first_of("f");
	return (fPos != input.find_last_of("f") || dotPos != input.find_last_of(".")
			|| fPos - dotPos == 1 || !std::isdigit(input[dotPos + 1]) || dotPos == 0);
}

static bool isChar(string const &input)
{
	return (input.length() == 1 && isprint(input[0]));
}

static void printChar(int type, int i, char c)
{
	if (type != NAN_INF && (i >= 0 && i <= UCHAR_MAX))
	{
		if (std::isprint(i))
			cout << "char: '" << c << "'" << endl;
		else
			cout << "char: Non displayable" << endl;
	}
	else
		cout << "char: impossible" << endl;
}

static void printInt(int type, string const &input, int i)
{
	double check = std::atof(input.c_str());

	if (type != NAN_INF && (check >= INT_MIN && check <= INT_MAX))
		cout << "int: " << i << endl;
	else
		cout << "int: impossible" << endl;
}

static void printNanInf(string const &input, string const &type)
{
	if (input == "nan" || input == "nanf")
	{
		cout << type << ": nan";
		if (type == "float")
			cout << "f";
		cout << endl;
	}
	else if (input == "+inf" || input == "+inff")
	{
		cout << type << ": +inf";
		if (type == "float")
			cout << "f";
		cout << endl;
	}
	else if (input == "-inf" || input == "-inff")
	{
		cout << type << ": -inf";
		if (type == "float")
			cout << "f";
		cout << endl;
	}
	else if (input == "inf" || input == "inff")
	{
		cout << type << ": inf";
		if (type == "float")
			cout << "f";
		cout << endl;
	}
}

static void printFloat(int type, string const &input, float f)
{
	if (type != NAN_INF)
	{
		double val = std::atof(input.c_str());
		if (type == INT && (val < INT_MIN || val > INT_MAX))
			cout << "float: impossible" << endl;
		else
			cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << endl;
	}
	else
		printNanInf(input, "float");
}

static void printDouble(int type, string const &input, double d)
{
	if (type != NAN_INF)
	{
		double val = std::atof(input.c_str());
		if (type == INT && (val < INT_MIN || val > INT_MAX))
			cout << "double: impossible" << endl;
		else
			cout << "double: " << std::fixed << std::setprecision(1) << d << endl;
	}
	else
		printNanInf(input, "double");
}

static void print(int type, string const &input, char c, int i, float f, double d)
{
	printChar(type, i, c);
	printInt(type, input, i);
	printFloat(type, input, f);
	printDouble(type, input, d);
}

void fromChar(int type, string const &input)
{
	char	c = static_cast<unsigned char>(input[0]);
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);
	print(type, input, c, i, f, d);
}

void fromInt(int type, string const &input)
{
	int		i = std::atoi(input.c_str());
	char	c = static_cast<unsigned char>(i);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);
	print(type, input, c, i, f, d);
}

void fromFloat(int type, string const &input)
{
	float	f = std::atof(input.c_str());
	char	c = static_cast<unsigned char>(f);
	int		i = static_cast<int>(f);
	double	d = static_cast<float>(f);
	print(type, input, c, i, f, d);
}

void fromDouble(int type, string const &input)
{
	double	d = std::atof(input.c_str());
	char	c = static_cast<unsigned char>(d);
	int		i = static_cast<int>(d);
	float	f = static_cast<float>(d);
	print(type, input, c, i, f, d);
}

int parseInput(string const &input)
{
	if (isChar(input))
		return CHAR;
	else if (isSpecialChar(input))
		return CHAR;
	else if (isInt(input))
		return INT;
	else if (isDouble(input))
		return isInvalidDouble(input) ? ERROR : DOUBLE;
	else if (isFloat(input))
		return isInvalidFloat(input) ? ERROR : FLOAT;
	else if (isNanInf(input))
		return NAN_INF;
	else if (hasInvalidSignal(input))
		return ERROR;
	return ERROR;
}

void ScalarConverter::convert(string const &input)
{
	int type = parseInput(input);
	switch (type)
	{
		case CHAR:
			fromChar(type, input);
			break;
		case INT:
			fromInt(type, input);
			break;
		case FLOAT:
			fromFloat(type, input);
			break;
		case DOUBLE:
			fromDouble(type, input);
			break;
		case NAN_INF:
			fromDouble(type, input);
			break;
		case ERROR:
			cout << "Error: Impossible to print or input not convertable" << endl;
			break;
	}
}
