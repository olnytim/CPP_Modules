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

using std::endl;
using std::cout;
using std::string;
using std::vector;

class BitcoinExchange {
private:
    vector<std::pair<string, double>> data;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange( const BitcoinExchange &toCopy );
    BitcoinExchange &operator=( const BitcoinExchange &toCopy );

    void readData( const string &filename );
    void printData() const;
};

#endif
