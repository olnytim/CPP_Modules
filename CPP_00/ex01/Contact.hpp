#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <string>
//#include "PhoneBook.hpp"

class Contact {

public:
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	darkest_secret;

	Contact() : first_name(""), last_name(""), nick_name(""), phone_number(""), darkest_secret("") {} // is it needed?

	bool isEmpty() {
		return (first_name.empty() && last_name.empty() && nick_name.empty()
			&& phone_number.empty() && darkest_secret.empty());
	}

	void	display_contact(std::string i) const {
		std::cout << i << std::endl;
		std::cout << formatted_output(first_name) << std::endl;;
		std::cout << formatted_output(last_name) << std::endl;;
		std::cout << formatted_output(nick_name) << std::endl;
		std::cout << formatted_output(phone_number) << std::endl;
		std::cout << formatted_output(darkest_secret) << std::endl;
	}

private:

	std::string	formatted_output(const std::string &text) const {
		if (text.size() > 10) {
			return (text.substr(0, 9) + ".");
		}
		return (text);
	}
};

#endif