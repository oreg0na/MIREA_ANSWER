#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

template <class _VectorType, class _NumberType>
std::vector<_VectorType> get_simple_devinders(_NumberType _number) {
	std::vector<_VectorType> devinders = {};
	_NumberType number_buffer = _number;
	while (number_buffer != 1) {
		if (number_buffer % 5 == 0) {
			devinders.push_back(5);
			number_buffer /= 5;
		} else if (number_buffer % 3 == 0) {
			devinders.push_back(3);
			number_buffer /= 3;
		} else if (number_buffer % 2 == 0) {
			devinders.push_back(2);
			number_buffer /= 2;
		} else return std::vector<_VectorType>();
	}
	return devinders;
}

int main() {
	size_t index = 0;
	std::cin >> index;
	if (index == 1) std::cout << 1;
	else {
		size_t number = 2;
		size_t last_index = 2;
		while (1) {
			if (last_index == index) {
				std::cout << number;
				break;
			}

			number += 1;
			std::vector<size_t> devinders = get_simple_devinders<size_t>(number);
			if (devinders.size() > 0) last_index += 1;
		}
	}
}
