#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

#include "Contact.hpp"

class PhoneBook {

public:
	PhoneBook() : _contactsCounter(0) {}
	void	contact_added(const Contact &contact);
	void	displayContacts(void);
	const Contact	*getContact(string index);

private:

	Contact	_contacts[8];
	int	_contactsCounter;
	int	_temp;

	string	_formattedOutput(string text);
};

#endif