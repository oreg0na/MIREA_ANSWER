# Задание 1

```cpp
#include <iostream>
#include <cmath>

int main() {
	double number = 0.0;
	std::cin >> number;
	double index = 0.0;
	while (1) {
		double number_buffer = std::pow(2, index);
		if (number_buffer == number) {
			std::cout << 1;
			break;
		} else if (number_buffer > number) {
			std::cout << 0;
			break;
		}
		index += 1.0;
	}

}
```
