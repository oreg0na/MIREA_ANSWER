#include <iostream>
#include <vector>

template <class _Type>
std::ostream& operator << (std::ostream& _stream, std::vector<_Type> _vector) {
	_stream << '[';
	for (auto i = 0ull; i < _vector.size(); i++) {
		_stream << _vector[i];
		if (i != _vector.size() - 1) _stream << ", ";
	}
	_stream << ']';
	return _stream;
}


template <class _Type>
std::vector<_Type> get_simple_numbers(size_t _number) {
	std::vector<_Type> numbers = {};
	numbers.reserve(_number);
	for (auto i = 1ull; i < _number + 1; i++) numbers.push_back(i);
	for (auto i = 1ull; i < _number; i++) {
		for (auto j = 1ull; j <= i; j++) {
			numbers.erase(std::remove(
				numbers.begin(), numbers.end(), i + j + 2 * i * j
			), numbers.end());
		}
	}

	std::vector<_Type> result = {};
	for (auto i : numbers) {
		if (2 * i + 1 <= _number) result.push_back(2 * i + 1);
	}

	return result;
}

int main() {
	int64_t number = 0;
	std::cin >> number;
	std::cout << get_simple_numbers<uint64_t>(number);
}