# 2.2. Заработок в интернете

```cpp
#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    while (a != b){
        if (a % 2 == 0 && a / 2 >= b){
            a = a/2;
            cout << ":2" <<endl;
        } else {
            a = a - 1;
            cout << "-1" <<endl;
        }
    }
    return 0;
}
```