# 3.1. Пропускать не хорошо

```cpp
#include <iostream>
#include <vector>

using namespace std;

template <class _Type>
_Type find_pair(vector<_Type>& _array) {
	int64_t start_erase_index = -1;
	if (_array.size() > 0) {
		for (auto i = 0ull; i < _array.size(); i++) {
			if (start_erase_index == -1) {
				if (_array[i] == _array[i + 1]) {
					start_erase_index = i;
				}
			}
			else {
				if (i == _array.size() - 1 && _array[i] == _array[i - 1]) {
					_array.erase(_array.begin() + start_erase_index, _array.begin() + i + 1);
					return i - start_erase_index + 1;
				} else if (_array[i] != _array[i - 1]) {
					_array.erase(_array.begin() + start_erase_index, _array.begin() + i);
					return i - start_erase_index;
				}
			}
		}
	}

	return 0;
}

int main() {
	size_t count_numbers = 0;
	cin >> count_numbers;
	vector<size_t> numbers;
	size_t result = 0;

	for (auto i = 0ull; i < count_numbers; i++) {
		size_t number_buffer = 0;
		cin >> number_buffer;
		numbers.push_back(number_buffer);
	}

	while (1) {
		size_t result_buffer = find_pair(numbers);
		if (!result_buffer) break;
		result += result_buffer;
	}

	cout << result << endl;
}
```