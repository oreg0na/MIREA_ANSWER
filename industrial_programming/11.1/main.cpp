#include <iostream>
#include <cmath>

template <class number_type>
number_type f_pow(number_type _number, size_t _index){
	if(_index == 0) return 1;
    number_type n_buffer = _number;
    for (auto i = 1ull; i < _index; i++) n_buffer *= _number;
    return n_buffer;
}

int main(){
    double number = 0.0, base = 0.0;
    std::cin >> number >> base;
    std::cout << f_pow(number, base);
}
