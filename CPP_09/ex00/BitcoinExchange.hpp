#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include <map>
#include <algorithm>

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
    int year;
    int month;
    int day;
    float value;
    int cur_year;
    int cur_month;
    int cur_day;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange( const BitcoinExchange &toCopy );
    BitcoinExchange &operator=( const BitcoinExchange &toCopy );

    void setData( const string &date, float value );
    void outputMap( const string &data );
    void getDateTime();
    bool loop( const string &line );
    void readData( const string &filename );
    static vector<string> ft_split(const string &str, char sep);
    static void throwException( Cases key, const string &str );
    void niceCode( std::ifstream &file );
    bool checkDate( const string &date );
};

#endif
