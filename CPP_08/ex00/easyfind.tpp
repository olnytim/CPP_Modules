#include "easyfind.hpp"

template <typename T>
int	easyfind(T &container, int value) {
	typename T::iterator iter = std::find(container.begin(), container.end(), value);
	if (iter != container.end())
		cout << value << " is found in container" << endl;
	else
		throw std::out_of_range("Value hasn't been found");
	return *iter;
}