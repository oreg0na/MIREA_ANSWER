# Без легенды

``` cpp
#include <iostream>
#include <unordered_map>
#include <cctype>
#include <algorithm>

template <class number_type>
number_type function(std::string _firstNumber, std::string _action, std::string _secondNumber) {
    number_type first_number = std::stod(_firstNumber), second_number = std::stod(_secondNumber);
    std::unordered_map<std::string, number_type(*)(number_type, number_type)> operations {
        {"+", [](number_type a, number_type b) { return a + b; }},
        {"-", [](number_type a, number_type b) { return a - b; }},
        {"*", [](number_type a, number_type b) { return a * b; }},
        {"/", [](number_type a, number_type b) { return a / b; }}
    };
    return operations[_action](first_number, second_number);
}

bool is_digit(const std::string& _number) {
    return std::all_of(_number.begin(), _number.end(), ::isdigit);
}

int main() {
    std::string number1, number2;
    std::cin >> number1 >> number2;
    if (is_digit(number2)) {
        std::cout << function<double>(number1, "*", number2) << std::endl;
    } else {
        std::string number3;
        std::cin >> number3;
        std::cout << function<double>(number1, number2, number3) << std::endl;
    }
}
```
