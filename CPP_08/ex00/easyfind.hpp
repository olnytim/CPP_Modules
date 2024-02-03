#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;

template <typename T>
int	easyfind(T &container, int value) {
	typename T::const_iterator iter = std::find(container.cbegin(), container.cend(), value);
	if (iter != container.end())
		cout << value << " is found in the container" << endl;
	else
		throw std::out_of_range("Value not found in the container");
	return *iter;
}

#endif