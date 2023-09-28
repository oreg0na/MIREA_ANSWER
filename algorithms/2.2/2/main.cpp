#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

template <class _Type>
bool is_simple(_Type _number) noexcept {
	for (auto i = 2ull; i < static_cast<decltype(i)>(std::sqrt(_number)) + 1; i++) {
		if (_number % i == 0) return false;
	}
	return true;
}

template <class _VectorType, class _NumberType>
std::vector<_VectorType> get_simple_devinders(_NumberType _number) {
	std::vector<_VectorType> devinders = {};
	_NumberType number_buffer = _number;
	while (number_buffer != 1) {
		if (number_buffer % 7 == 0) {
			devinders.push_back(7);
			number_buffer /= 7;
		} else if (number_buffer % 5 == 0) {
			devinders.push_back(5);
			number_buffer /= 5;
		} else if (number_buffer % 3 == 0) {
			devinders.push_back(3);
			number_buffer /= 3;
		} else if (number_buffer % 2 == 0) {
			devinders.push_back(2);
			number_buffer /= 2;
		} else throw "Not simple devinder";
	}
	return devinders;
}

template <class _Type>
size_t convert(_Type _number) noexcept {
	if (_number > 10 && is_simple(_number)) return 0;
	else if (_number == 1) return 1;
	else if (_number == 0) return 0;
	try {
		std::vector<size_t> devinders = get_simple_devinders<size_t>(_number);
		while (1) {
			if (std::count(devinders.begin(), devinders.end(), 3) >= 2) {
				devinders.erase(std::find(devinders.begin(), devinders.end(), 3));
				devinders.erase(std::find(devinders.begin(), devinders.end(), 3));
				devinders.push_back(9);
			} else if (std::count(devinders.begin(), devinders.end(), 2) >= 3) {
				devinders.erase(std::find(devinders.begin(), devinders.end(), 2));
				devinders.erase(std::find(devinders.begin(), devinders.end(), 2));
				devinders.erase(std::find(devinders.begin(), devinders.end(), 2));
				devinders.push_back(8);
			} else if (std::count(devinders.begin(), devinders.end(), 3) >= 1 && std::count(devinders.begin(), devinders.end(), 2) >= 1) {
				devinders.erase(std::find(devinders.begin(), devinders.end(), 3));
				devinders.erase(std::find(devinders.begin(), devinders.end(), 2));
				devinders.push_back(6);
			} else if (std::count(devinders.begin(), devinders.end(), 2) >= 2) {
				devinders.erase(std::find(devinders.begin(), devinders.end(), 2));
				devinders.erase(std::find(devinders.begin(), devinders.end(), 2));
				devinders.push_back(4);
			} else break;
		}
		std::sort(devinders.begin(), devinders.end());
		size_t result_number = 0;
		for (auto devinder : devinders) {
			result_number = (result_number * 10 + devinder);
		}
		return result_number;
	} catch (const char* _error) {
		return 0;
	}
	return 1;
}

int main() {
	size_t number = 0;
	std::cin >> number;
	std::cout << convert(number);
}
