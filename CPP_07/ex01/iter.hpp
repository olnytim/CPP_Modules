#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <typename T>
void	print(const T &array) {
	cout << array << endl;
}

template <typename T>
void	iter(T *array, size_t length, void(*fn)(const T&)) {
	for (size_t i = 0; i < length; ++i)
		fn(array[i]);
}

template <typename T1, typename T2>
void	iter(T1 *array, size_t length, void(*fn)(const T2&)) {
	for (size_t i = 0; i < length; ++i)
		fn(array[i]);
}

#endif