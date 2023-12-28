#include "Array.hpp"

Array<T>::Array() : _array(new T), _size(0) {}

Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

Array<T>::Array( const Array &toCopy ) {
	Array<T>::operator=(toCopy);
}

Array &Array<T>::operator=(const Array &toCopy) {
	if (this != &toCopy) {
		delete [] _array;
		_array = new T[toCopy.getSize()];
		_size = toCopy.getSize();
		for (unsigned int i = 0; i < _size; ++i)
			_array[i] = toCopy._array[i];
	}
	return *this;
}

Array<T>::~Array() {
    delete [] _array;
}

unsigned int Array<T>::getSize() {
	return _size;
}

T &Array<T>::operator[](unsigned int i) const {
    if (i >= _size)
        throw OutOfBoundsException();
    return _array[i];
}

const char *Array<T>::OutOfBoundsException::what() const throw() {
    return "Index is out of bounds";
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &array) {
    for (unsigned int i = 0; i < array.size(); ++i)
        out << array[i] << " ";
    return out;
}