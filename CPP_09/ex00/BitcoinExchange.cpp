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
            cout << "Reading: " << line << endl;
            cout << "iss: " << iss.str() << endl;
            iss >> date >> price;
            data.push_back(std::make_pair(date, price));
        }
    }
}

void BitcoinExchange::printData() const {
    for (auto &d : data) {
        cout << d.first << " " << d.second << endl;
    }
}