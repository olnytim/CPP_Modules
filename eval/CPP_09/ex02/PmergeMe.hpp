#ifndef EVAL_PMERGEME_HPP
#define EVAL_PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <list>

using std::cout;
using std::endl;
using std::cerr;

class PmergeMe {
private:
    PmergeMe();
    PmergeMe(const PmergeMe &toCopy);
    PmergeMe &operator=(const PmergeMe &toCopy);
    ~PmergeMe();

public:
    PmergeMe(int ac, char **av);
    template<class T>
            void displayContainer(const T &container) const;
    void mergeInsertSortDeque(std::deque<int> &container);
    void mergeInsertSortList(std::list<int> &container);
};


#endif
