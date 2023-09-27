# 1.3. Элементарный калькулятор

```cpp
#include <iostream>
using namespace std;
int main()
{
	float a;
	float b;
	string c;
	cin >> a >> c >> b;
	if(c == "+"){
	    cout << a + b;
	}
	if(c == "-"){
	    cout << a - b;
	}
	if(c == "*"){
	    cout << a * b;
	}
	if(c == "/"){
	    cout << a / b;
	}
	return 0;
}
```