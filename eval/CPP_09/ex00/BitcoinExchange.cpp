#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : year(2009), month(01), day(01), value(0), cur_year(0), cur_month(0), cur_day(0) {
    flag = 0;
    std::ifstream file("../CPP_09/ex00/data.csv");
//    std::ifstream file("data.csv");
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
    value = toCopy.value;
    year = toCopy.year;
    month = toCopy.month;
    day = toCopy.day;
    cur_year = toCopy.cur_year;
    cur_month = toCopy.cur_month;
    cur_day = toCopy.cur_day;
    flag = toCopy.flag;
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
    cur_year = ltm->tm_year + 1900;
    cur_month = ltm->tm_mon + 1;
    cur_day = ltm->tm_mday;
}

static string &leftTrim(string &str) {
    size_t pos = str.find_first_not_of(SKIP);
    if (pos != string::npos)
        str.erase(0, pos);
    return str;
}

static string &rightTrim(string &str) {
    size_t pos = str.find_last_not_of(SKIP);
    if (pos != string::npos)
        str.erase(pos + 1, string::npos);
    return str;
}

static string trim(string &str) {
    return rightTrim(leftTrim(str));
}

void BitcoinExchange::setData(const std::string &date, float val) {
    data.insert(std::pair<string, float>(date, val));
}

bool BitcoinExchange::checkDate(const string &date) {
    getDateTime();
    vector<string> vectorDate = ft_split(date, '-');
    if (vectorDate.size() != 3)
        return false;
    try {
        std::istringstream iss(vectorDate[0]);
        iss >> year;
        std::istringstream iss1(vectorDate[1]);
        iss1 >> month;
        std::istringstream iss2(vectorDate[2]);
        iss2 >> day;
    }
    catch (const std::invalid_argument &except) {
        return false;
    }
    for (size_t i = 0; i < vectorDate.size(); i++) {
        for (size_t j = 0; j < vectorDate[i].size(); j++) {
            if (isdigit(vectorDate[i][j]))
                continue;
            else
                return false;
        }
    }
    if (year >= 2009 && year <= cur_year) {
        int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (month == 2) {
            if (day > months[month - 1] + ((!(year % 4) && (year % 100)) || (!(year % 400))))
                return false;
        }
        else if (day > months[month - 1])
            return false;
    }
    if (year > cur_year || (year == cur_year && month > cur_month) ||
        (year == cur_year && month == cur_month && day > cur_day)) {
        return false;
    }
    return true;
}

vector<string> BitcoinExchange::ft_split(const std::string &str, char sep) {
    vector<string> result;
    string item;
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

void BitcoinExchange::outputMap(const string &date) {
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

bool BitcoinExchange::loop(const string &line) {
    vector<string> vectorLine = ft_split(line, '|');
    if (vectorLine[1].empty() || vectorLine.size() != 2) {
        throwException(FORMAT_ERROR, line);
        return false;
    }
    string date = trim(vectorLine[0]);
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        throwException(FORMAT_ERROR, date);
        return false;
    }
    string temp = trim(vectorLine[1]);
    cout << "temp: " << temp << endl;
    if (std::count(temp.begin(), temp.end(), '.') > 1) {
        throwException(FORMAT_ERROR, vectorLine[1]);
        return false;
    }
    if (temp[temp.length() - 1] == 'f')
        temp = temp.substr(0, temp.length() - 1);
    for (string::iterator it = temp.begin(); it != temp.end(); ++it) {
        if (!isdigit(*it) && *it != '.') {
            throwException(FORMAT_ERROR, vectorLine[1]);
            return false;
        }
    }
    std::istringstream iss(vectorLine[1]);
    if (!checkDate(date)) {
        throwException(FORMAT_ERROR, date);
        return false;
    }
    iss >> value;
    if (value > 1000) {
        throwException(BIG_VALUE, vectorLine[1]);
        return false;
    }
    else if (value < 0) {
        throwException(NEGATIVE_VALUE, vectorLine[1]);
        return false;
    }
    outputMap(date);
    return true;
}

void BitcoinExchange::niceCode(std::ifstream &file) {
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
}

void BitcoinExchange::readData(const string &filename) {
    std::ifstream file(filename.c_str());
    if (file.is_open()) {
        niceCode(file);
        file.close();
    }
    else
        throwException(INVALID_DATE, filename);
}