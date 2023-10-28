#include "PhoneBook.hpp"

void	PhoneBook::contact_added(const Contact &contact) {
	if (contacts_counter < 8) {
		contacts[contacts_counter++] = contact;
	}
	else {
		if (!temp || temp > 7) {
			temp = 0;
		}
		contacts[temp++] = contact;
	}
}

void	PhoneBook::displayContacts(void) {
	Contact	contact;
	cout << endl << "|" << setw(10) << "   Index  ";
	cout << "|" << setw(10) << formattedOutput("First name");
	cout << "|" << setw(10) << formattedOutput("Last name");
	cout << "|" << setw(10) << formattedOutput("Nick name") << "|" << endl;
	for (int i = 0; i < contacts_counter; i++) {
		contact.preloadContacts(contacts[i], i);
	}
}

const Contact	*PhoneBook::getContact(string index) {
	if (stoi(index) >= contacts_counter)
		return (nullptr);
	return (&contacts[stoi(index)]);
}

std::string	PhoneBook::formattedOutput(string text) {
	if (text.size() > 10) {
		return (text.substr(0, 9) + ".");
	}
	return (text);
}