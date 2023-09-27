# 2.1. Скупой платит дважды

```cpp
#include <iostream>
using namespace std;
int main() {
    long double x, y, poc;
    poc = 10;
    int day = 1;
    cin >> x >> y >> poc;
    while (x < y){
        x = x + (x / 100) * poc;
        day++;
    }
    cout << day;
    return 0;
}
```