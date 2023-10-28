#include "Contact.hpp"

bool Contact::isEmpty(void) {
	return (first_name.empty() && last_name.empty() && nick_name.empty()
			&& phone_number.empty() && darkest_secret.empty());
}

void	Contact::displayContact(void) const {
	cout << endl << "First name is > " << first_name << endl;;
	cout << "Last name is > " << last_name << endl;;
	cout << "Nick name is > " << nick_name << endl;
	cout << "Phone Number is > " << phone_number << endl;
	cout << "Darkest_secret is > " << darkest_secret << endl;
}

string	Contact::formattedOutput(const string text) const {
	if (text.size() > 10) {
		return (text.substr(0, 9) + ".");
	}
	return (text);
}

void	Contact::setContact(void) {
	cout << endl << "Enter First name: ";
	cin >> first_name;
	if (cin.eof()) return ;
	cout << "Enter Last name: ";
	cin >> last_name;
	if (cin.eof()) return ;
	cout << "Enter Nickname: ";
	cin >> nick_name;
	if (cin.eof()) return ;
	cout << "Enter Phone number: ";
	cin >> phone_number;
	if (cin.eof()) return ;
	cout << "Enter Darkest secret: ";
	cin >> darkest_secret;
	if (cin.eof()) return ;
}

void	Contact::preloadContacts(Contact contact, int i) const {
	cout << "|" << setw(10) << i;
	cout << "|" << setw(10) << formattedOutput(contact.first_name);
	cout << "|" << setw(10) << formattedOutput(contact.last_name);
	cout << "|" << setw(10) << formattedOutput(contact.nick_name) << "|" << endl;
}