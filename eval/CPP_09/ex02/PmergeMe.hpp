#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
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
using std::vector;

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
    static void printVector( const string& );
    static void printList( const string& );
    static void insertVector( vector<int>&, vector<int>& );
    static void insertionSort( vector<int>& );
    static void sortVector( vector<int>& );
    static double sortVector( void );
    static void insertLists( list<int>&, list<int>& );
    static void listInsertion( list<int>& );
    static void sortList( list<int>& );
    static double sortList( void );

    static vector<int>	_vecSequence;
    static list<int>	_listSequence;

    static void printVectorRange(size_t start, size_t end);

    static void printListRange(list<int>::iterator start, list<int>::iterator end);
};

#endif