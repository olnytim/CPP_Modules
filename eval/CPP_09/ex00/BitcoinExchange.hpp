#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include <map>

#define SKIP " \t\n\r"

using std::endl;
using std::cout;
using std::string;
using std::vector;
using std::map;

class BitcoinExchange {
private:
    enum Cases {
        INVALID_DATE,
        INVALID_VALUE,
        NEGATIVE_VALUE,
        FORMAT_ERROR,
        BIG_VALUE,
        INVALID_LINE,
        INVALID_RATE
    };

    map<string, float> data;
    int flag;
    float value;
    int year;
    int month;
    int day;
    int cur_year;
    int cur_month;
    int cur_day;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange( const BitcoinExchange &toCopy );
    BitcoinExchange &operator=( const BitcoinExchange &toCopy );

    map<string, float> &getData();
    void setData( const string &date, float value );
    void outputMap( string data );
    void getDateTime();
    bool loop( string line );
    void readData( const string filename );
    vector<string> ft_split(const string &str, char sep);
    void throwException( Cases key, const string &str );
    void niceCode( std::ifstream &file );
    bool checkDate( const string &date );
};

#endif
