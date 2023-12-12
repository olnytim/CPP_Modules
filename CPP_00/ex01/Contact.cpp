#include "Contact.hpp"

Contact::Contact() : _firstName(string()), _lastName(string()), _nickName(string()), _phoneNumber(string()), _darkestSecret(string()) {}

bool Contact::isEmpty(void) {
	return _firstName.empty() && _lastName.empty() && _nickName.empty()
			&& _phoneNumber.empty() && _darkestSecret.empty();
}

void	Contact::displayContact(void) const {
	cout << endl << "First name is > " << _firstName << endl;;
	cout << "Last name is > " << _lastName << endl;;
	cout << "Nickname is > " << _nickName << endl;
	cout << "Phone number is > " << _phoneNumber << endl;
	cout << "Darkest secret is > " << _darkestSecret << endl;
}

string	Contact::_formattedOutput(const string text) const {
	if (text.size() > 10) {
		return text.substr(0, 9) + ".";
	}
	return (text);
}

int	Contact::setContact(void) {
	cout << endl << "Enter First name: ";
	cin >> _firstName;
	if (cin.eof()) return 1;
	cout << "Enter Last name: ";
	cin >> _lastName;
	if (cin.eof()) return 1;
	cout << "Enter Nickname: ";
	cin >> _nickName;
	if (cin.eof()) return 1;
	cout << "Enter Phone number: ";
	cin >> _phoneNumber;
	if (cin.eof()) return 1;
	cout << "Enter Darkest secret: ";
	cin >> _darkestSecret;
	if (cin.eof()) return 1;
	return 0;
}

void	Contact::preloadContacts(Contact contact, int i) const {
	cout << "|" << setw(10) << i;
	cout << "|" << setw(10) << _formattedOutput(contact._firstName);
	cout << "|" << setw(10) << _formattedOutput(contact._lastName);
	cout << "|" << setw(10) << _formattedOutput(contact._nickName) << "|" << endl;
}
