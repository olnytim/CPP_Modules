#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : year(2009), month(01), day(01) {
    flag = 0;
    std::ifstream file("../../CPP_09/ex00/data.csv");
    if (!file.is_open()) {
        throwException(INVALID_DATE, "data.csv");
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t pos = line.find(',');
        if (pos == std::string::npos) {
            throwException(FORMAT_ERROR, line);
        }
        string date = line.substr(0, pos);
        try {
            std::istringstream iss(line.substr(pos + 1));
            iss >> value;
        }
        catch (const std::invalid_argument &except) {
            std::cerr << "Error: Invalid parameter" << endl;
            continue;
        }
        setData(date, value);
    }
    file.close();
}

BitcoinExchange::~BitcoinExchange() {
	data.clear();
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &toCopy ) {
    data = toCopy.data;
}

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &toCopy ) {
    if (this != &toCopy) {
        data = toCopy.data;
    }
    return *this;
}

void BitcoinExchange::throwException(BitcoinExchange::Cases key, const std::string &str) {
    switch (key) {
        case INVALID_DATE:
            cout << "Error: could not open file." << endl;
            break;
        case INVALID_VALUE:
            cout << "Error: Invalid value -> " << str << endl;
            break;
        case NEGATIVE_VALUE:
            cout << "Error: not a positive number." << endl;
            break;
        case FORMAT_ERROR:
            cout << "Error: bad input => " << str << endl;
            break;
        case BIG_VALUE:
            cout << "Error: too large a number." << endl;
            break;
        case INVALID_LINE:
            cout << "Error: Invalid line -> " << str << endl;
            break;
        case INVALID_RATE:
            cout << "Error: Invalid rate -> " << str << endl;
            break;
    }
}

void BitcoinExchange::getDateTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    year = ltm->tm_year + 1900;
    month = ltm->tm_mon + 1;
    day = ltm->tm_mday;
}

static string &leftTrim(string &str) {
    str.erase(0, str.find_first_not_of(SKIP));
    return str;
}

static string &rightTrim(string &str) {
    str.erase(str.find_first_of(SKIP), string::npos);
    return str;
}

static string trim(string &str) {
    return rightTrim(leftTrim(str));
}

void BitcoinExchange::setData(const std::string &date, float val) {
    data.insert(std::pair<string, float>(date, val));
}

map<string, float> &BitcoinExchange::getData() {
    return data;
}

vector<string> BitcoinExchange::ft_split(const std::string &str, char sep) {
    vector<string> result;
    string item = "";
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == sep) {
            result.push_back(item);
            item = "";
        }
        else
            item += str[i];
    }
    result.push_back(item);
    return result;
}

void BitcoinExchange::outputMap(string date) {
    map<string, float>::iterator it = data.begin();
    if (data.find(date) != data.end())
        cout << date << " => " << value << " = " << value * data[date] << endl;
    else {
        it = data.lower_bound(date);
        if (it == data.begin()) {
            it = data.end();
            --it;
        }
        else
            --it;
        cout << date << " => " << value << " = " << value * it->second << endl;
    }
}

bool BitcoinExchange::loop(string line) {
    vector<string> vectorLine = ft_split(line, '|');
    if (vectorLine[1].length() == 0 || vectorLine.size() != 2) {
        throwException(FORMAT_ERROR, line);
        return false;
    }
    string date = trim(vectorLine[0]);
    try {
        std::istringstream iss(vectorLine[1]);
        iss >> value;
        if (value > 1000) {
            throwException(BIG_VALUE, vectorLine[1]);
            return false;
        } else if (value < 0) {
            throwException(NEGATIVE_VALUE, vectorLine[1]);
            return false;
        }
    }
    catch (const std::invalid_argument &except) {
        throwException(INVALID_VALUE, vectorLine[1]);
        return false;
    }
    outputMap(date);
    return true;
}

void BitcoinExchange::readData(const string filename) {
    std::ifstream file(filename.c_str());
    if (file.is_open()) {
        string line;
        vector<string> vectorLine;
        std::getline(file, line);
        if (line == "date | value") {
            while (std::getline(file, line))
                if (!loop(line))
                    continue;
        }
        else
            throwException(FORMAT_ERROR, line);
        file.close();
    }
    else
        throwException(INVALID_DATE, filename);
}
