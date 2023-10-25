# 12.1 Дам, но не дам

``` cpp
#include <iostream>
#include <string>
#include <cstdint>

template <class number_type>
void reverse_numbers(number_type _number, size_t _count) {
	if (!_count) return;
	number_type number = 0;
	std::cin >> number;
	reverse_numbers(number, _count - 1);
	std::cout << number << ' ';
}

int main() {
	size_t count = 0;
	std::cin >> count;

	uint64_t number = 0;
	std::cin >> number;
	reverse_numbers(number, count - 1);
	std::cout << number;
}
```
