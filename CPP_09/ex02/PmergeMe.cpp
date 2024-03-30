#include "PmergeMe.hpp"

deque<int>	PmergeMe::_dequeSequence;
list<int>	PmergeMe::_listSequence;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& toCopy) {
    *this = toCopy;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& toCopy) {
    if (this != &toCopy) {
        _dequeSequence = toCopy._dequeSequence;
        _listSequence = toCopy._listSequence;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

template <typename T>
T	PmergeMe::incrementIterator(T it, typename std::iterator_traits<T>::difference_type n) {
    while (n > 0) {
        ++it;
        --n;
    }
    return it;
}

template <typename T>
T	PmergeMe::decrementIterator(T it, typename std::iterator_traits<T>::difference_type n) {
    while (n > 0) {
        --it;
        --n;
    }
    return it;
}

bool PmergeMe::containsOnlyPositiveNumbers(const string& input) {
    for (size_t index = 0; index < input.size(); ++index) {
        char currentChar = input[index];
        if (!std::isdigit(currentChar) && currentChar != ' ' && currentChar != '+')
            return false;
        if (currentChar == '+' && !std::isdigit(input[index + 1]))
            return false;
    }
    return true;
}

void PmergeMe::fillContainers(const string& str) {
    std::stringstream ss(str);
    string tmp;
    long num;

    while (ss >> tmp) {
        std::stringstream converter(tmp);
        if (!(converter >> num))
            throw std::logic_error("Error: Unable to convert string to number.");

        if (num <= 0)
            throw std::logic_error("Error: Negative number or zero.");
        if (num > std::numeric_limits<int>::max() || tmp.size() > 12)
            throw std::logic_error("Error: Overflow.");

        _dequeSequence.push_back(static_cast<int>(num));
        _listSequence.push_back(static_cast<int>(num));
    }

    if (_dequeSequence.empty() || _listSequence.empty())
        throw std::logic_error("Error: Empty sequence.");
}

void PmergeMe::printDeque(const string& message) {
    cout << message << "\t[deque]: \t";

    size_t size = _dequeSequence.size();
    if (size <= 13) {
        printDequeRange(0, size - 1);
    }
    else
    {
        printDequeRange(0, 9);
        cout << "[...] ";
        printDequeRange(size - 3, size - 1);
    }
    cout << endl;
}

void PmergeMe::printDequeRange(size_t start, size_t end) {
    for (size_t i = start; i <= end; ++i) {
        cout << _dequeSequence[i];
        if (i != end)
            cout << " ";
    }
}

void PmergeMe::printList(const string& message) {
    cout << message << "\t[list]: \t";

    size_t size = _listSequence.size();
    if (size <= 13) {
        printListRange(_listSequence.begin(), _listSequence.end());
    } else {
        printListRange(_listSequence.begin(), incrementIterator(_listSequence.begin(), 10));
        cout << "[...] ";
        printListRange(decrementIterator(_listSequence.end(), 3), _listSequence.end());
    }
    cout << endl;
}

void PmergeMe::printListRange(list<int>::iterator start, list<int>::iterator end) {
    for (list<int>::iterator it = start; it != end; ++it) {
        cout << *it;
        if (incrementIterator(it) != end)
            cout << " ";
    }
}

void PmergeMe::insertionSort(deque<int>& nums) {
    for (size_t i = 1; i < nums.size(); ++i) {
        size_t  j = i;
        while (j > 0 && nums[j] < nums[j - 1]) {
            std::swap(nums[j], nums[j - 1]);
            --j;
        }
    }
}

void PmergeMe::insertDeque(deque<int>& bigNums, deque<int>& smallNums) {
    int n = 0;
    int power = 0;
    size_t startIndex = 0;
    size_t endIndex = 0;

    for (size_t i = 0; i < smallNums.size();) {
        ++power;
        n = static_cast<int>(std::pow(2.0, static_cast<double>(power)) - n);
        startIndex += n;
        endIndex = startIndex - n;

        if (startIndex > smallNums.size())
            startIndex = smallNums.size();

        for (size_t j = startIndex - 1; j >= endIndex;) {
            deque<int>::iterator insertionPoint = std::upper_bound(bigNums.begin(), bigNums.end(), smallNums[j]);
            bigNums.insert(insertionPoint, smallNums[j]);
            ++i;
            if (j == 0)
                break;
            --j;
        }
    }
}

void	PmergeMe::sortDeque(deque<int>& nums) {
    int unpairedNumber;
    deque<int> bigNumbers, smallNumbers;
    size_t size = nums.size() / 2 + (nums.size() % 2);

    if (nums.size() % 2 == 0)
        unpairedNumber = -1;
    else
        unpairedNumber = nums.back();

    if (nums.size() == 2 || nums.size() == 3) {
        insertionSort(nums);
        return;
    }

    for (size_t i = 0; i < size; ++i) {
        if (i != size - 1 || nums.size() % 2 == 0) {
            int firstNum = nums[i * 2], secondNum = nums[i * 2 + 1];
            if (firstNum > secondNum)
                std::swap(firstNum, secondNum);
            bigNumbers.push_back(secondNum);
            smallNumbers.push_back(firstNum);
        }
    }

    if (unpairedNumber != -1)
        smallNumbers.push_back(unpairedNumber);
    sortDeque(bigNumbers);
    insertionSort(bigNumbers);
    insertDeque(bigNumbers, smallNumbers);
    nums = bigNumbers;
}

double	PmergeMe::sortDeque() {
    clock_t startTime = clock();
    if (_dequeSequence.size() != 1)
        sortDeque(_dequeSequence);
    clock_t endTime = clock();

    double duration = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000.0;

    return duration;
}

void	PmergeMe::listInsertion(list<int>& nums) {
    for (list<int>::iterator i = incrementIterator(nums.begin()); i != nums.end(); ++i) {
        int tmp = *i;
        list<int>::iterator j = i;
        while (j != nums.begin() && *decrementIterator(j) > tmp) {
            *j = *decrementIterator(j);
            --j;
        }
        *j = tmp;
    }
}

void	PmergeMe::insertLists(list<int>& bigNumbers, list<int>& smallNumbers) {
    int currentPower = 0;
    int currentN = 0;
    list<int>::iterator startIndex = bigNumbers.begin();
    list<int>::iterator endIndex = startIndex;

    for (list<int>::iterator it = smallNumbers.begin(); it != smallNumbers.end();) {
        ++currentPower;
        currentN = static_cast<int>(std::pow(2.0, static_cast<double>(currentPower)) - currentN);
        std::advance(startIndex, currentN);
        endIndex = startIndex;
        std::advance(endIndex, -currentN);

        if (startIndex != smallNumbers.end())
            startIndex = smallNumbers.end();

        for (list<int>::iterator j = decrementIterator(startIndex); j != decrementIterator(endIndex);) {
            bigNumbers.insert(std::upper_bound(bigNumbers.begin(), bigNumbers.end(), *j), *j);
            ++it;
            if (j == smallNumbers.begin())
                break;
            --j;
        }
    }
}

void    PmergeMe::sortList(list<int>& nums) {
    int unpairedNumber;
    list<int> bigNumbers, smallNumbers;
    size_t size = nums.size() / 2 + (nums.size() % 2);

    if (nums.size() % 2 == 0)
        unpairedNumber = -1;
    else
        unpairedNumber = nums.back();

    if (nums.size() == 2 || nums.size() == 3) {
        listInsertion(nums);
        return;
    }

    for (size_t i = 0; i < size; ++i) {
        if (i != size - 1 || nums.size() % 2 == 0) {
            int n = *incrementIterator(nums.begin(), i * 2);
            int m = *incrementIterator(nums.begin(), i * 2 + 1);
            if (n > m)
                std::swap(n, m);
            bigNumbers.push_back(m);
            smallNumbers.push_back(n);
        }
    }

    if (unpairedNumber != -1)
        smallNumbers.push_back(unpairedNumber);
    sortList(bigNumbers);
    insertLists(bigNumbers, smallNumbers);
    nums = bigNumbers;
}

double PmergeMe::sortList() {
    clock_t startTime = clock();
    if (_listSequence.size() != 1)
        sortList(_listSequence);
    clock_t endTime = clock();

    double duration = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000.0;

    return duration;
}

void	PmergeMe::FordJohnson(const string& str) {
    _listSequence.clear();
    _dequeSequence.clear();

    if (str.empty() || !containsOnlyPositiveNumbers(str))
        throw std::logic_error(("Error: invalid argument."));

    fillContainers(str);
    printList("Before:");
    printDeque("Before:");

    double dequeTime = sortDeque();
    double listTime = sortList();

    printList("After:");
    printDeque("After:");
    cout <<"Time to process a range of "<< _dequeSequence.size() << " elements with deque :\t" << dequeTime << "\tmilliseconds" << endl;
    cout <<"Time to process a range of "<< _listSequence.size() << " elements with list   :\t" << listTime << "\tmilliseconds" << endl;
}