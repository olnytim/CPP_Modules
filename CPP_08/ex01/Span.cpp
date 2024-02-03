#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int N) : N(N) {}

Span& Span::operator=(const Span &toCopy) {
	if (this != &toCopy)
		this->N = toCopy.N;
	return *this;
}

Span::Span(const Span &toCopy) {
	Span::operator=(toCopy);
}

Span::~Span() {
	numbers.clear();
}

void Span::addNumber(int number) {
	if (numbers.size() >= this->N)
		throw std::out_of_range("Span is full. Cannot add more numbers");
	numbers.push_back(number);
}

template <typename T>
void Span::addNumbers(T first, T last) {
	while (first != last)
		addNumber(*first++);
}

unsigned int Span::shortestSpan() const {
	if (numbers.size() > 0) {
		std::vector<int> sortedNumbers = numbers;
		std::sort(sortedNumbers.begin(), sortedNumbers.end());

		int min = std::numeric_limits<int>::max();
		for (std::vector<int>::iterator i = sortedNumbers.begin() + 1; i != sortedNumbers.end(); ++i) {
			int span = *i - *(i - 1);
			if (span < min)
				min = span;
		}
		return min;
	}
	throw std::logic_error("Invalid number of numbers to search");
}

unsigned int Span::longestSpan() const {
	if (numbers.size() > 0) {
		std::vector<int>::const_iterator min = std::min_element(numbers.cbegin(), numbers.cend());
		std::vector<int>::const_iterator max = std::max_element(numbers.cbegin(), numbers.cend());
		return *max - *min;
	}
	throw std::logic_error("Invalid number of numbers to search");
}