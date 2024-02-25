#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : year(2009), month(01), day(01) {
    flag = 0;
    bool firstString = false;
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        throwException(INVALID_DATE, "data.csv");
    }
    std::string line;
    while (std::getline(file, line)) {
        if (!firstString) {
            firstString = true;
            continue;
        }
        size_t pos = line.find(',');
        if (pos == std::string::npos) {
            throwException(FORMAT_ERROR, line);
        }
        string date = line.substr(0, pos);
        double value;
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
            cout << "Invalid date -> " << str << endl;
            break;
        case INVALID_VALUE:
            cout << "Invalid value -> " << str << endl;
            break;
        case NEGATIVE_VALUE:
            cout << "Negative value -> " << str << endl;
            break;
        case FORMAT_ERROR:
            cout << "Format error -> " << str << endl;
            break;
        case BIG_VALUE:
            cout << "Big value -> " << str << endl;
            break;
        case INVALID_LINE:
            cout << "Invalid line -> " << str << endl;
            break;
        case INVALID_RATE:
            cout << "Invalid rate -> " << str << endl;
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
    str.erase(str.find_first_not_of(SKIP) + 1, string::npos);
    return str;
}

static string trim(string &str) {
    return leftTrim(rightTrim(str));
}

void BitcoinExchange::setData(const std::string &date, float value) {
    data.insert(std::pair<string, float>(date, value));
}

map<string, float> &BitcoinExchange::getData() {
    return data;
}

vector<string> BitcoinExchange::ft_split(const string &str, char sep) {
    vector<string> result;
    string item = "";
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == sep) {
            result.push_back(item);
            while (str[i] == sep) {
                ++i;
            }
            --i;
            item = "";
        }
        else {
            item += str[i];
        }
    }
    result.push_back(item);
    return result;
}

void BitcoinExchange::readData(const string filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throwException(INVALID_DATE, filename);
        return ;
    }
    bool firstString = false;
    std::string line;
    vector<string> vectorLine;

    // check first line here

    while (std::getline(file, line)) {
        if (!firstString) {
            firstString = true;
            continue;
        }
        vectorLine = ft_split(line, '|');
        if (vectorLine[1].length() == 0 || vectorLine.size() != 2) {
            throwException(FORMAT_ERROR, line);
            continue;
        }
        cout << vectorLine[1] << "hello" << endl;
        map<string, float>::iterator it = data.lower_bound(trim(vectorLine[0]));
        if (it != data.end()) {
            if (it == data.begin()) {
                it = data.end();
                --it;
            }
            std::pair<string, float> pair = *it;
            cout << "here: " << pair.first << " " << pair.second << endl;
            double value;
            try {
                std::istringstream iss(vectorLine[1]);
                iss >> value;
                cout << "value: " << pair.second << endl;
                if (value > 1000) {
                    throwException(BIG_VALUE, vectorLine[1]);
                    continue;
                }
                else if (value < 0) {
                    throwException(NEGATIVE_VALUE, vectorLine[1]);
                    continue;
                }
                cout << pair.first << " => " << vectorLine[1] << " => " << value * pair.second << endl;
            }
            catch (const std::invalid_argument &except) {
                throwException(INVALID_VALUE, vectorLine[1]);
                continue;
            }
        }
        cout << endl;
    }
    file.close();
}