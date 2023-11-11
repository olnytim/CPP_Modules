#include "Harl.hpp"

void Harl::debug( void ) {
	cout << "* DEBUG *" << " I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << endl;
}

void Harl::info( void ) {
	cout << "* INFO *" << " I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << endl;
}

void Harl::warning( void ) {
	cout << "* WARNING *" << " I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << endl;
}

void Harl::error( void ) {
	cout << "* ERROR *" << " This is unacceptable! I want to speak to the manager now." << endl;
}

void Harl::complain(std::string level) {
	void	(Harl::*array[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error } ;
	string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*array[i])();
			return ;
		}
	}
	cout << "Input correct command, please. ty ;)" << endl;
}