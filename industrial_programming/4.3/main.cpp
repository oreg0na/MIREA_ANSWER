#include <fstream>
#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>

template <class _Type>
std::string to_bin(_Type _number) {
	std::string new_number;
	_Type number_buffer = _number;
	while (number_buffer > 0) {
		new_number += std::to_string(number_buffer % 2);
		number_buffer /= 2;
	}
	std::reverse(new_number.begin(), new_number.end());
	return new_number;
}

int main() {
	std::fstream input_file("input.txt", std::ios::in);
	std::fstream output_file("output.txt", std::ios::out);

	std::string input_string;
	std::getline(input_file, input_string);
	size_t index = 0;
	uint64_t number = 0;
	while (1) {
		if (input_string[index] >= '0' && input_string[index] <= '9') {
			number = number * 10 + (input_string[index] - '0');
		} else {
			if (number) output_file << to_bin(static_cast<uint64_t>(number));
			output_file << input_string[index];
			number = 0;
		}
		if (index == input_string.size() - 1) {
			if (number) output_file << to_bin(static_cast<uint64_t>(number));
			break;
		}
		index += 1;
	}
}