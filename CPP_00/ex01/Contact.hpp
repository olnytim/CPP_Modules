#ifndef CONTACT_HPP
# define CONTACT_HPP

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
	Contact();
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