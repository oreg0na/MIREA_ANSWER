#include <iostream>
#include <string>
#include <cmath>

template <class _Type>
bool is_pow(_Type _number) {
    double number_buffer = std::sqrt(_number);
    return static_cast<_Type>(number_buffer) == number_buffer ? true : false;
}

int main() {
    int64_t number = 0;
    std::cin >> number;
    std::cout << (is_pow(number) ? "true" : "false");
}