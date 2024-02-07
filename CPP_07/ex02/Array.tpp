#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(nullptr), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array( const Array &toCopy ) : _array(nullptr), _size(0) {
	Array<T>::operator=(toCopy);
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &toCopy) {
	if (this != &toCopy) {
		delete [] _array;
		_size = toCopy.size();
		_array = new T[toCopy.size()];
		for (unsigned int i = 0; i < _size; ++i)
			_array[i] = toCopy._array[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
    delete [] _array;
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}

template <typename T>
T &Array<T>::operator[](unsigned int i) {
    if (i >= _size)
        throw OutOfBoundsException();
    return _array[i];
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const {
	if (i >= _size)
		throw OutOfBoundsException();
	return _array[i];
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
    return "Index is out of bounds";
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &array) {
    for (unsigned int i = 0; i < array.size(); ++i)
        out << array[i];
    return out;
}