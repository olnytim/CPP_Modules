#include "PmergeMe.hpp"

vector<int>	PmergeMe::_vecSequence;
list<int>	PmergeMe::_listSequence;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& toCopy) {
    *this = toCopy;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& toCopy) {
    if (this != &toCopy) {
        _vecSequence = toCopy._vecSequence;
        _listSequence = toCopy._listSequence;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

template <typename T>
T	PmergeMe::myNext(T it, typename std::iterator_traits<T>::difference_type n) {
    while (n > 0) {
        ++it;
        --n;
    }
    return it;
}

template <typename T>
T	PmergeMe::myPrev(T it, typename std::iterator_traits<T>::difference_type n) {
    while (n > 0) {
        --it;
        --n;
    }
    return it;
}

bool	PmergeMe::positiveNumbers(const string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (!std::isdigit(str[i]) && str[i] != ' ' && str[i] != '+')
            return false;
        if (str[i] == '+' && !std::isdigit(str[i + 1]))
            return false;
    }
    return true;
}

void	PmergeMe::fillContainers(const string&	str) {
    std::stringstream   ss(str), sp(str);
    string  tmp;
    long    num;

    while (sp >> tmp) {
        ss >> num;
        if (num <= 0)
            throw std::logic_error("Error: Negative number or zero.");
        if (num > std::numeric_limits<int>::max() || tmp.size() > 12)
            throw std::logic_error("Error: Overflow.");
        _vecSequence.push_back(static_cast<int>(num));
        _listSequence.push_back(static_cast<int>(num));
    }
    if (_vecSequence.empty() || _listSequence.empty())
        throw std::logic_error("Error: Empty sequence.");
}

void	PmergeMe::printVector(const string& message) {
    cout << message << "\t[vector]: \t";

    if (_vecSequence.size() <= 13) {
        for (size_t i = 0; i < _vecSequence.size(); ++i) {
            cout << _vecSequence[i];
            if (i != _vecSequence.size() - 1)
                cout << " ";
        }
    }
    else {
        for (size_t i = 0; i < 10; ++i)
            cout << _vecSequence[i] << " ";
        cout << "[...] ";
        for (size_t i = _vecSequence.size() - 3; i < _vecSequence.size(); ++i) {
            cout << _vecSequence[i];
            if (i != _vecSequence.size() - 1)
                cout << " ";
        }
    }
    cout << endl;
}

void	PmergeMe::printList(const string& message) {
    cout << message << "\t[list]: \t";
    if (_listSequence.size() <= 13) {
        for (list<int>::iterator it = _listSequence.begin(); it != _listSequence.end(); ++it) {
            cout << *it;
            if (it != --_listSequence.end())
                cout << " ";
        }
    }
    else
    {
        int printedCount = 0;
        for (list<int>::iterator it = _listSequence.begin(); printedCount != 10 && it != _listSequence.end(); ++it) {
            ++printedCount;
            cout << *it << " ";
        }
        cout << "[...] ";
        list<int>::iterator lastButOne = _listSequence.end();
        std::advance(lastButOne, -3);
        for (list<int>::iterator it = lastButOne; it != _listSequence.end(); ++it) {
            cout << *it;
            if (it != --_listSequence.end())
                cout << " ";
        }
    }
    cout << endl;
}

void PmergeMe::vectorInsertion(vector<int>& nums) {
    for (size_t i = 1; i < nums.size(); ++i) {
        size_t  j = i;
        while (j > 0 && nums[j] < nums[j - 1]) {
            std::swap(nums[j], nums[j - 1]);
            j--;
        }
    }
}

void PmergeMe::vectorInsert(vector<int>& bigNums, vector<int>& smallNums) {
    int n = 0;
    int power = 0;
    size_t  start_index = 0;
    size_t  end_index = 0;

    for (size_t i = 0; i < smallNums.size();) {
        ++power;
        n = int(pow(2, power) - n);
        start_index += n;
        end_index = start_index - n;

        if (start_index > smallNums.size())
            start_index = smallNums.size();

        for (size_t j = start_index - 1; j >= end_index;) {
            bigNums.insert(std::upper_bound(bigNums.begin(), bigNums.end(), smallNums[j]), smallNums[j]);
            ++i;
            if (j == 0)
                break;
            --j;
        }
    }
}

void	PmergeMe::sortVectorAlgorithm(vector<int>& nums) {
    int unpaired;
    vector<int> bigNums, smallNums;
    size_t size = nums.size() / 2 + (nums.size() % 2);

    unpaired = ((nums.size() % 2 == 0) ? -1 : nums[nums.size() - 1]);
    if (nums.size() == 2 || nums.size() == 3) {
        vectorInsertion(nums);
        return ;
    }

    for (size_t i = 0; i < size; ++i) {
        if (i != size - 1 || nums.size() % 2 == 0) {
            int n = nums[i * 2], m = nums[i * 2 + 1];
            if (n > m)
                std::swap(n, m);
            bigNums.push_back(m);
            smallNums.push_back(n);
        }
    }
    if (unpaired != -1)
        smallNums.push_back(unpaired);
    sortVectorAlgorithm(bigNums);
    vectorInsert(bigNums, smallNums);
    nums = bigNums;
}

double	PmergeMe::sortVector() {
    clock_t start = clock();
    if (_vecSequence.size() != 1)
        sortVectorAlgorithm(_vecSequence);
    clock_t end = clock();

    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;

    return duration;
}

void	PmergeMe::listInsertion(list<int>& nums) {
    for (list<int>::iterator i = myNext(nums.begin()); i != nums.end(); ++i) {
        int tmp = *i;
        list<int>::iterator j = i;
        while (j != nums.begin() && *myPrev(j) > tmp) {
            *j = *myPrev(j);
            j--;
        }
        *j = tmp;
    }
}

void	PmergeMe::listInsert(list<int>& bigNums, list<int>& smallNums) {
    int n = 0;
    int power = 0;
    list<int>::iterator	start_index = bigNums.begin();
    list<int>::iterator	end_index = start_index;

    for (list<int>::iterator it = smallNums.begin(); it != smallNums.end();) {
        ++power;
        n = int(pow(2, power) - n);
        std::advance(start_index, n);
        end_index = start_index;
        std::advance(end_index, -n);

        if (start_index != smallNums.end())
            start_index = smallNums.end();

        for (list<int>::iterator j = myPrev(start_index); j != myPrev(end_index);) {
            bigNums.insert(std::upper_bound(bigNums.begin(), bigNums.end(), *j), *j);
            ++it;
            if (j == smallNums.begin())
                break;
            --j;
        }
    }
}

void		PmergeMe::sortListAlgorithm(list<int>& nums) {
    int unpaired;
    list<int> bigNums, smallNums;
    size_t size = nums.size() / 2 + (nums.size() % 2);

    unpaired = ((nums.size() % 2 == 0) ? -1 : nums.back());
    if (nums.size() == 2 || nums.size() == 3) {
        listInsertion(nums);
        return;
    }

    for (size_t i = 0; i < size; ++i) {
        if (i != size - 1 || nums.size() % 2 == 0) {
            int	n = *myNext(nums.begin(), i * 2);
            int	m = *myNext(nums.begin(), i * 2 + 1);
            if (n > m)
                std::swap(n, m);
            bigNums.push_back(m);
            smallNums.push_back(n);
        }
    }
    if (unpaired != -1)
        smallNums.push_back(unpaired);
    sortListAlgorithm(bigNums);
    listInsert(bigNums, smallNums);
    nums = bigNums;
}

double PmergeMe::sortList() {
    clock_t start = clock();
    if (_listSequence.size() != 1)
        sortListAlgorithm(_listSequence);
    clock_t end = clock();

    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;

    return (duration);
}

void	PmergeMe::FordJohnson(const string& str) {
    _listSequence.clear();
    _vecSequence.clear();

    if (str.empty() || !positiveNumbers(str))
        throw std::logic_error(("Error: invalid argument."));

    fillContainers(str);

    printList("Before:");
    printVector("Before:");

    double	vecTime, listTime;

    vecTime = sortVector();
    listTime = sortList();

    printList("After:");
    printVector("After:");

    cout <<"Time to process a range of "<< _vecSequence.size() << " elements with vector :\t" << vecTime << "\tmilliseconds" << endl;
    cout <<"Time to process a range of "<< _listSequence.size() << " elements with list   :\t" << listTime << "\tmilliseconds" << endl;
}