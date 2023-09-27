# Задание 3

```cpp
#include <iostream>

template <class _Type>
bool is_simple(_Type _number) {
	for (auto i = 2ull; i < static_cast<decltype(i)>(std::sqrt(_number)) + 1; i++) {
		if (_number % i == 0) return false;
	}
	return true;
}

template <class _Type>
bool is_special_number(_Type _number) {
	bool is_2_devinder = false, is_3_devinder = false, is_5_devinder = false;
	for (auto i = 2ull; i < _number; i++) {
		if (_number % i == 0) {
			if (i == 2) is_2_devinder = true;
			else if (i == 3) is_3_devinder = true;
			else if (i == 5) is_5_devinder = true;
			else {
				if (is_simple(i)) return false;
			}
		}
	}

	if (is_2_devinder && is_3_devinder && is_5_devinder) return true;
	return false;
}

int main() {
	size_t index = 0;
	std::cin >> index;
	size_t finded_numbers = 0;
	int64_t number = 30;
	while (1) {
		if (is_special_number(number)) {
			finded_numbers += 1;
			if (finded_numbers == index) break;
		}
		number += 1;
	}
	std::cout << number;
}
```