# 10.3 Числа Бибоначчи

``` cpp
#include <iostream>

using namespace std;

int main() {
    int64_t a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    int64_t first_n = a;
    int64_t second_n = b;
    for (auto i = 2; i < c; i++){
        int64_t n_buffer = first_n * second_n;
        first_n = second_n,second_n = n_buffer;
    }
    cout << second_n << endl;
}
```
