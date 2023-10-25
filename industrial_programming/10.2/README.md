# 10.2. Случайности не случайны

cpp ```
#include <iostream>
#include <random>
#include <ranges>
#include <algorithm>

int main() {
    size_t count = 0;
    double summ = 0.0;
    std::cin >> count;
    std::random_device device;
    std::mt19937 generate(device());
    double* num = new double[count];
    for (auto i = 0ull; i < count; i++) {
        num[i] = static_cast<double>(i+1);
        summ += num[i];
    }
    std::ranges::shuffle(&num[0], &num[count-1], generate);
    std::cout << summ;
    delete[] num;
}
```
