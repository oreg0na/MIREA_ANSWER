# 11.2 Утро воскресенья

``` cpp
#include <iostream>

using namespace std;

template <class number_type>
number_type gsd(number_type _firstNumber, number_type _secondNumber) {
    if(_secondNumber == 0) return _firstNumber;
    if(_firstNumber > _secondNumber) return gsd(_secondNumber, _firstNumber % _secondNumber);
    else return gsd(_firstNumber, _secondNumber % _firstNumber);
}

int main(){
    size_t a = 0, b = 0;
    cin >> a >> b;
    cout << gsd(a, b);
}
```
