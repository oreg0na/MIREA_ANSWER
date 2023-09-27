#include <iostream>
#include <vector>
#include <math.h>

template <class _Type>
bool is_simple(_Type _number) {
	for (auto i = 2ull; i < static_cast<decltype(i)>(std::sqrt(_number)) + 1; i++) {
		if (_number % i == 0) return false;
	}
	return true;
}

template <class _Type>
_Type merssena_number(_Type _index) {
	return static_cast<_Type>(std::pow(2, _index)) - 1;
}

template <class _Type>
bool luka_lemera_test(_Type _merssenaNumber, _Type _merssenaIndex) {
	_Type tested_number = 4;
    for (auto i = 0ull; i < _merssenaIndex - 2; i++) tested_number = ((tested_number * tested_number) - 2);
	return tested_number % _merssenaNumber == 0 ? true : false;
}

int main() {
	int64_t index = 0;
	std::cin >> index;
	if (index % 2 == 1 && is_simple(index)) {
		int64_t number = merssena_number(index);
		std::cout << std::format("Merssena number: {}", number) << std::endl;
		if (luka_lemera_test(number, index)) {
			std::cout << "Luka Lummera test passing succesed" << std::endl;
		}
	} else {
		std::cout << "Number not come not condition";
	}
}
