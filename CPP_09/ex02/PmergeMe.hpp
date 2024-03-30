#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <stdexcept>
#include <sstream>
#include <limits>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <deque>

using std::cout;
using std::endl;
using std::string;
using std::list;
using std::deque;
using std::deque;

class PmergeMe {
public:
    static void	FordJohnson(const string&);

private:
    PmergeMe( void );
    PmergeMe( const PmergeMe& );
    ~PmergeMe( void );
    PmergeMe&	operator=( const PmergeMe& );

    template <typename T>
    static T incrementIterator(T, typename std::iterator_traits<T>::difference_type n = 1);
    template <typename T>
    static T decrementIterator(T, typename std::iterator_traits<T>::difference_type n = 1);

    static bool containsOnlyPositiveNumbers( const string& );
    static void fillContainers( const string& );
    static void printDeque( const string& );
    static void printList( const string& );
    static void insertDeque( deque<int>&, deque<int>& );
    static void insertionSort( deque<int>& );
    static void sortDeque( deque<int>& );
    static double sortDeque( void );
    static void insertLists( list<int>&, list<int>& );
    static void listInsertion( list<int>& );
    static void sortList( list<int>& );
    static double sortList( void );

    static deque<int>	_dequeSequence;
    static list<int>	_listSequence;

    static void printDequeRange(size_t start, size_t end);

    static void printListRange(list<int>::iterator start, list<int>::iterator end);
};

#endif