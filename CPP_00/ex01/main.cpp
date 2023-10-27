#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void) {
	PhoneBook	phonebook;
	while (1) {
		std::cout << "Enter one of three commands ('EXIT', 'ADD', 'SEARCH'): ";
		std::string request;
		std::cin >> request;
		if (request == "ADD") {
			Contact		contact;
			std::cout << "Enter first name: ";
			std::cin >> contact.first_name;
			std::cout << "Enter last name: ";
			std::cin >> contact.last_name;
			std::cout << "Enter nickname: ";
			std::cin >> contact.nick_name;
			std::cout << "Enter phone number: ";
			std::cin >> contact.phone_number;
			std::cout << "Enter darkest secret: ";
			std::cin >> contact.darkest_secret;
			if (!contact.isEmpty()) {
				std::cout << "Everything is alright!" << std::endl;
				phonebook.contact_added(contact);
			}
			else {
				std::cout << "Contact can't contain empty fields." << std::endl;
			}
		}
		else if (request == "SEARCH") {
			phonebook.display_contacts();
			std::string	index;
			std::cout << "Enter index to display: ";
			std::cin >> index;
			if (index >= "0" && index <= "9") {
				const Contact *found_contact = phonebook.get_contact(index);
				found_contact->display_contact(index);
			}
			else {
				std::cout << "Wrong contact" << std::endl;
			}
		}
		else if (request == "EXIT") return (0);
	}
}