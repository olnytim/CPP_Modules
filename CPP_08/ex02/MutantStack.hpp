#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <deque>

using std::cout;
using std::endl;
using std::string;

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	MutantStack();
	MutantStack( const MutantStack &toCopy );
	MutantStack &operator=( const MutantStack &toCopy );
	~MutantStack();

	// iterator
	typedef typename Container::iterator iterator;
	iterator begin( void );
	iterator end( void );

	// const iterator
	typedef typename Container::const_iterator const_iterator;
	const_iterator begin( void ) const;
	const_iterator end( void ) const;

	// reverse iterator
	typedef typename Container::reverse_iterator reverse_iterator;
	reverse_iterator rbegin( void );
	reverse_iterator rend( void );

	// const reverse iterator
	typedef typename Container::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator rbegin( void ) const;
	const_reverse_iterator rend( void ) const;
};

#include "MutantStack.tpp"

#endif