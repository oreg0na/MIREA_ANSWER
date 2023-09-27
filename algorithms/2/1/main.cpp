#include <iostream>
#include <algorithm>

using namespace std;
int find_nod_devinder(size_t _firstNumber, size_t _secondNumber)
{
    size_t firstNumber = _firstNumber;
    size_t secondNumber = _secondNumber;
    while (1) {
        if (firstNumber % secondNumber == 0) {
            return secondNumber;
        }
        else {
            size_t first_number_buffer = secondNumber;
            secondNumber = (firstNumber % secondNumber);
            firstNumber = first_number_buffer;
        }
    }
}

size_t find_nod_minus(size_t _firstNumber, size_t _secondNumber) {
    size_t max_number = max(_firstNumber, _secondNumber);
    size_t min_number = min(_firstNumber, _secondNumber);
    while (1) {
        if (max_number == min_number) return min_number;
        size_t buffer_number = max_number - min_number;
        max_number = max(buffer_number, min_number);
        min_number = min(buffer_number, min_number);
    }
}

int main(){
    int64_t first_number = 0, second_number = 0;
    cin >> first_number >> second_number;
    if (first_number % 2 == 0 && second_number % 2 == 0) cout << find_nod_minus(first_number, second_number);
    else cout << find_nod_devinder(first_number, second_number);
}