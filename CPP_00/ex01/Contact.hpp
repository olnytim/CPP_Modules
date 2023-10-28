#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <iomanip>
#include <string>
using std::cout;
using std::string;
using std::endl;
using std::cin;
using std::setw;
using std::getline;

class Contact {

public:
	Contact() : first_name(string()), last_name(string()), nick_name(string()), phone_number(string()), darkest_secret(string()) {} // is it needed?
	bool	isEmpty(void);
	void	displayContact(void) const;
	void	setContact(void);
	void	preloadContacts(Contact contact, int i) const;

private:
	string	first_name;
	string	last_name;
	string	nick_name;
	string	phone_number;
	string	darkest_secret;

	string	formattedOutput(const string text) const;
};

#endif