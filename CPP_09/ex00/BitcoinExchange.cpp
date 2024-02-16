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

const char *BitcoinExchange::InvalidDate::what() const throw() {
    return "Invalid Date";
}

const char *BitcoinExchange::InvalidValue::what() const throw() {
	return "Invalid Value";
}

void BitcoinExchange::getDateTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    year = ltm->tm_year + 1900;
    month = ltm->tm_mon + 1;
    day = ltm->tm_mday;
}

void BitcoinExchange::readData( const string &filename ) {
    std::ifstream file(filename);
    getDateTime();
    if (file.is_open()) {
        string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            string date;
            double price;
            iss >> date;
            iss.ignore(3);
            iss >> price;
            vector<string> check;
            std::istringstream tokenStream(date);
            string token;
            while (std::getline(tokenStream, token, '-'))
            	check.push_back(token);
            if (check[0].length() == 4 && check[1].length() == 2 && check[2].length() == 2) {
                if (price >= 0 && price <= 1000) {
                    int check_year = std::stoi(check[0]);
                    int check_month = std::stoi(check[1]);
                    int check_day = std::stoi(check[2]);
                    if (check_year >= 2009 && check_year <= year) {
                        if (check_year == year) {
                            if (check_month > month)
                                throw InvalidDate();
                            else if (check_month == month) {
                                if (check_day > day)
                                    throw InvalidDate();
                            }
                        }
                        switch (check_month) {
                            case 1:
                            case 3:
                            case 5:
                            case 7:
                            case 8:
                            case 10:
                            case 12:
                                if (check_day >= 1 && check_day <= 31)
                                    break;
                            case 4:
                            case 6:
                            case 9:
                            case 11:
                                if (check_day >= 1 && check_day <= 30)
                                    break;
                            case 2: {
                                if (check_year % 4 == 0) {
                                    if (check_day >= 1 && check_day <= 29)
                                        break;
                                }
                                else if (check_day >= 1 && check_day <= 28)
                                    break;
                            }
                            default:
                                throw InvalidDate();
                        }
                    }
                    data.push_back(std::make_pair(date, price));
                }
                else
                    throw InvalidDate();
            }
            else
                throw InvalidValue();
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