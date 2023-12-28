#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <typename T>
void	print_element(T &array) {
	cout << array << endl;
}

template <typename T>
void	increment(T &n) {
	++n;
}

template <typename T>
void	iter(T *array, size_t length, void(*fn)(T&)) {
	for (size_t i = 0; i < length; ++i)
		fn(array[i]);
}

#endif