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

const char *BitcoinExchange::InvalidInput::what() const throw() {
    return "Invalid input";
}

char **string.split(char delimeter) {
    char **arr = new char*[3];
    int i = 0, j = 0, k = 0;
    while (i < length) {
        if (str[i] == delimeter) {
            arr[j] = new char[i - k + 1];
            for (int l = k; l < i; ++l)
                arr[j][l - k] = str[l];
            arr[j][i - k] = '\0';
            k = i + 1;
            ++j;
        }
        ++i;
    }
    arr[j] = new char[i - k + 1];
    for (int l = k; l < i; ++l)
        arr[j][l - k] = str[l];
    arr[j][i - k] = '\0';
    return arr;
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
    if (file.is_open()) {
        string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            string date;
            double price;
            iss >> date;
            iss.ignore(3);
            iss >> price;
            char ** check = date.split('-');
            if (check[0].length() == 4 && check[1].length() == 2 && check[2].length() == 2 && (price >= 0 && price <= 1000)) {
                if (check[0] >= 2009 && check[0] <= year) {
                    if (check[0] == year) {
                        if (check[1] > month)
                            throw InvalidInput();
                        else if (check[1] == month)
                            if (check[2] > day)
                                throw InvalidInput();
                    }
                    switch (check[1]) {
                        case 1:
                        case 3:
                        case 5:
                        case 7:
                        case 8:
                        case 10:
                        case 12:
                            if (check[2] >= 1 && check[2] <= 31)
                                break;
                        case 4:
                        case 6:
                        case 9:
                        case 11:
                            if (check[2] >= 1 && check[2] <= 30)
                                break;
                        case 2:
                            if (check[0] % 4 == 0)
                                if (check[2] >= 1 && check[2] <= 29)
                                    break;
                            else
                                if (check[2] >= 1 && check[2] <= 28)
                                    break;
                        default:
                            throw InvalidInput();
                    }
                    data.push_back(std::make_pair(date, price));
                }
                else
                    throw InvalidInput();
            }
            else
                throw InvalidInput();
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