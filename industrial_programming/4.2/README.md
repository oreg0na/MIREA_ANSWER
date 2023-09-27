# 4.2. Попей глицина

```cpp
#include <iostream>
#include <vector>
#include <string>

int main() {
	std::string sequence;
	size_t index = 0;
	std::cin >> sequence >> index;

	for (auto i = 0ull; i < index - 1; i++) {
		size_t number = sequence[0] - '0', count_numbers = 1;
		std::string new_sequence;
		for (auto j = 1ull; j < sequence.size(); j++) {
			if (number == (sequence[j] - '0')) {
				count_numbers += 1;
			} else {
				new_sequence += std::to_string(count_numbers);
				new_sequence += std::to_string(number);
				number = (sequence[j] - '0');
				count_numbers = 1;
			}
		}
		new_sequence += std::to_string(count_numbers);
		new_sequence += std::to_string(number);
		sequence = new_sequence;
	}
	std::cout << sequence;
}
```