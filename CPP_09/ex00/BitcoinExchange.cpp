#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &toCopy ) {
    data = toCopy.data;
}

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &toCopy ) {
    if (this != &toCopy) {
        data = toCopy.data;
    }
    return *this;
}

void BitcoinExchange::readData( const string &filename ) {
    std::ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            string date;
            double price;
            iss >> date;
            iss.ignore(3);
            iss >> price;
            data.push_back(std::make_pair(date, price));
        }
    }
}

void BitcoinExchange::printData() const {
    unsigned long i = 0;
    while (i < data.size())
    {
        cout << data[i].first << " " << data[i].second << endl;
        ++i;
    }
}