#include "PhoneBook.hpp"

void	PhoneBook::contact_added(const Contact &contact) {
	if (_contactsCounter < 8) {
		_contacts[_contactsCounter++] = contact;
	}
	else {
		if (!_temp || _temp > 7) {
			_temp = 0;
		}
		_contacts[_temp++] = contact;
	}
}

void	PhoneBook::displayContacts(void) {
	Contact	contact;
	cout << endl << "|" << setw(10) << "   Index  ";
	cout << "|" << setw(10) << _formattedOutput("First name");
	cout << "|" << setw(10) << _formattedOutput("Last name");
	cout << "|" << setw(10) << _formattedOutput(" Nickname ") << "|" << endl;
	for (int i = 0; i < _contactsCounter; i++) {
		contact.preloadContacts(_contacts[i], i);
	}
}

const Contact	*PhoneBook::getContact(string index) {
	if (stoi(index) >= _contactsCounter)
		return (nullptr);
	return &_contacts[stoi(index)];
}

string	PhoneBook::_formattedOutput(string text) {
	if (text.size() > 10) {
		return text.substr(0, 9) + ".";
	}
	return text;
}