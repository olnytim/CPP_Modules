#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <utility>
#include <ctime>

using std::endl;
using std::cout;
using std::string;
using std::vector;

class BitcoinExchange {
private:
    vector<std::pair<string, double> > data;
    int year;
    int month;
    int day;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange( const BitcoinExchange &toCopy );
    BitcoinExchange &operator=( const BitcoinExchange &toCopy );

    void getDateTime();
    void readData( const string &filename );
    void printData() const;

    class InvalidDate: public std::exception {
    public:
        virtual const char* what() const throw();
    };
	class InvalidValue: public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif
