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

void	ScalarConverter::print_char(char toPrint) {
	if (isprint(toPrint))
		cout << "char: '" << static_cast<char>(toPrint) << "'" << endl;
	else
		cout << "char: Non displayable" << endl;
}

void	ScalarConverter::print_int(int toPrint) {
	cout << "int: " << toPrint << endl;
}

void	ScalarConverter::print_float(float toPrint) {
	std::ostringstream	str;
	str << toPrint;
	string userInput = str.str();
	cout << "float: " << toPrint;
	if (!std::isinf(toPrint)) {
		if (userInput.find('.') == string::npos)
			cout << ".0f";
		else
			cout << "f";
	}
	cout << endl;
}

void	ScalarConverter::print_double(double toPrint) {
	std::ostringstream	str;
	str << toPrint;
	string userInput = str.str();
	cout << "double: " << toPrint;
	if (!std::isinf(toPrint) && (userInput.find('.') == string::npos))
		cout << ".0";
	cout << endl;
}

void	ScalarConverter::convert_to_char(const string &userInput) {
	char	str = userInput[0];
	ScalarConverter::print_char(static_cast<char>(str));
	ScalarConverter::print_int(static_cast<int>(str));
	ScalarConverter::print_float(static_cast<float>(str));
	ScalarConverter::print_double(static_cast<double>(str));
}

void	ScalarConverter::convert_to_int(const string &userInput) {
	char	num = std::atoi(userInput.c_str());
	ScalarConverter::print_char(static_cast<char>(num));
	ScalarConverter::print_int(static_cast<int>(num));
	ScalarConverter::print_float(static_cast<float>(num));
	ScalarConverter::print_double(static_cast<double>(num));
}

void	ScalarConverter::convert_to_float(const string &userInput) {
	char	num = std::atof(userInput.c_str());
	ScalarConverter::print_char(static_cast<char>(num));
	ScalarConverter::print_int(static_cast<int>(num));
	ScalarConverter::print_float(static_cast<float>(num));
	ScalarConverter::print_double(static_cast<double>(num));
}

void	ScalarConverter::convert_to_double(const string &userInput) {
	char	num = std::strtod(userInput.c_str(), NULL);
	ScalarConverter::print_char(static_cast<char>(num));
	ScalarConverter::print_int(static_cast<int>(num));
	ScalarConverter::print_float(static_cast<float>(num));
	ScalarConverter::print_double(static_cast<double>(num));
}

int	ScalarConverter::check_input_type(const string &userInput, size_t inputLength) {	
	bool dot = userInput.find('.') != string::npos;
	bool f = userInput.find('f') != string::npos;
	if (inputLength == 1 && !std::isdigit(userInput[0]))
		return ScalarConverter::CHAR;
	if (!f)
		return ScalarConverter::DOUBLE;
	if (inputLength <= 11 && !dot && !f) {
		long num = std::atol(userInput.c_str());
		if (num > INT_MIN && num < INT_MAX)
			return ScalarConverter::INT;
	}
	return ScalarConverter::FLOAT;
}

void ScalarConverter::convert(const string &userInput) {
	const size_t	inputLength = userInput.length();
	const int	inputType = ScalarConverter::check_input_type(userInput, inputLength);
	switch (inputType) {
		case CHAR:
			ScalarConverter::convert_to_char(userInput);
			break;
		case INT:
			ScalarConverter::convert_to_int(userInput);
			break;
		case DOUBLE:
			ScalarConverter::convert_to_double(userInput);
			break;
		default:
			ScalarConverter::convert_to_float(userInput);
			break;
	}
}