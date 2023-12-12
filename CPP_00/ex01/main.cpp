#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void) {
	PhoneBook	phonebook;
	while (1) {
		cout << endl << "Enter one of three commands ('EXIT', 'ADD', 'SEARCH'): ";
		string request;
		cin >> request;
		if (request == "ADD") {
			Contact		contact;
			int a = contact.setContact();
			if (a) {
				cout << endl << "Do not use CTRL + D!" << endl;
				return 1;
			}
			if (!contact.isEmpty()) {
				cout << "Contact was added!" << endl;
				phonebook.contactAdd(contact);
			}
			else {
				cout << "Contact can't contain empty fields!" << endl;
			}
		}
		else if (request == "SEARCH") {
			phonebook.displayContacts();
			string	index;
			cout << endl << "Enter index to display: ";
			cin >> index;
			if (index >= "0" && index <= "7") {
				const Contact *found_contact = phonebook.getContact(index);
				if (!found_contact) {
					cout << "Wrong contact. Use correct one!" << endl;
				}
				else found_contact->displayContact();
			}
			else {
				cout << "Wrong contact. Use correct one!" << endl;
			}
		}
		else if (cin.eof()) {
			cout << endl << "Do not use CTRL + D!" << endl;
			return 1;
		}
		else if (request == "EXIT")
			return 0;
		else
			cout << "Wrong argument. Try one of the list!" << endl;
	}
}
