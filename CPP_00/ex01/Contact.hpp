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
	Contact() : _firstName(string()), _lastName(string()), _nickName(string()), _phoneNumber(string()), _darkestSecret(string()) {} // is it needed?
	bool	isEmpty(void);
	void	displayContact(void) const;
	void	setContact(void);
	void	preloadContacts(Contact contact, int i) const;

private:
	string	_firstName;
	string	_lastName;
	string	_nickName;
	string	_phoneNumber;
	string	_darkestSecret;

	string	_formattedOutput(const string text) const;
};

#endif