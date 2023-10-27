#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

#include "Contact.hpp"

class PhoneBook {

public:
	PhoneBook() : contacts_counter(0) {}
	void	contact_added(const Contact &contact) {
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
	void	display_contacts() {
		for (int i = 0; i < contacts_counter; i++) {
			std::cout << i << "     ";
			std::cout << formatted_output(contacts[i].first_name) << "     ";
			std::cout << formatted_output(contacts[i].last_name) << "     ";
			std::cout << formatted_output(contacts[i].nick_name) << "     " << std::endl;
		}
	}
	const Contact	*get_contact(std::string index) {
		return (&contacts[std::stoi(index)]);
	}

private:

	Contact contacts[8];
	int contacts_counter;
	int	temp;

	std::string	formatted_output(std::string &text) {
		if (text.size() > 10) {
			return (text.substr(0, 9) + ".");
		}
		return (text);
	}
};

#endif