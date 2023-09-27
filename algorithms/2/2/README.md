# Задание 2

```cpp
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
std::vector<_Type> find_simple_numbers(_Type _number) {
	std::vector<_Type> numbers = {};
	_Type last_devinder = static_cast<_Type>(2);
	numbers.reserve(_number - 1);
	for (auto i = 2ull; i <= _number; i++) numbers.push_back(i);

	while (1) {
		bool is_deleted = false;
		std::vector<_Type> numbers_copy = numbers;
		for (auto i : numbers_copy) {
			if (i % last_devinder == 0 && i != last_devinder) {
				numbers.erase(std::remove(numbers.begin(), numbers.end(), i), numbers.end());
				is_deleted = true;
			}
		}
		if (!is_deleted) break;
		for (auto i = 0ull; i < numbers.size(); i++) {
			if (numbers[i] == last_devinder && i != numbers.size() - 2) {
				last_devinder = numbers[i + 1];
				break;
			}
		}
	}

	return numbers;
}

int main() {
	int64_t number = 0;
	std::cin >> number;
	std::cout << find_simple_numbers(number);
}
```