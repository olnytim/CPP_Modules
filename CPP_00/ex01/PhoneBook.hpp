#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

#include "Contact.hpp"

class PhoneBook {

public:
	PhoneBook() : contacts_counter(0) {}
	void	contact_added(const Contact &contact);
	void	displayContacts(void);
	const Contact	*getContact(string index);

private:

	Contact	contacts[8];
	int	contacts_counter;
	int	temp;

	string	formattedOutput(string text);
};

#endif