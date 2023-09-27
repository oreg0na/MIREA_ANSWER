#include <iostream>
#include <vector>
#include <chrono>
#include <string>

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
std::vector<_Type> random_number(size_t _counts) {
	std::tm now_time = {};
	__time64_t now_time_t = 0;
	_time64(&now_time_t);
	_localtime64_s(&now_time, &now_time_t);
	std::string random_str;
	random_str += now_time.tm_sec < 10 ? std::to_string(now_time.tm_sec) + "0" : std::to_string(now_time.tm_sec);
	random_str += now_time.tm_min < 10 ? std::to_string(now_time.tm_min) + "0" : std::to_string(now_time.tm_min);
	random_str += now_time.tm_hour > 6 ? "1" : "2";
	_Type last_number = static_cast<_Type>(atoll(random_str.c_str()));
	std::vector<_Type> numbers = {};
	for (auto i = 0ull; i < _counts; i++) {
		std::string buffer_number = std::to_string(static_cast<_Type>(std::pow(last_number, 2)));
		std::string new_number = buffer_number.substr(2, 5);
		last_number = static_cast<_Type>(std::atoll(new_number.c_str()));
		numbers.push_back(last_number);
	}
	return numbers;
}

int main() {
	std::cout << random_number<uint64_t>(10);
}