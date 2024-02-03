#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Span {
private:
	unsigned int	N;
	std::vector<int>	numbers;
	Span();
public:
	Span(unsigned int N);
	Span( const Span &toCopy );
	Span &operator=( const Span &toCopy );
	~Span();

	void	addNumber( int number );
	template <typename T>
	void	addNumbers( T first, T last );
	unsigned int	shortestSpan( void ) const;
	unsigned int	longestSpan( void ) const;
};

#endif