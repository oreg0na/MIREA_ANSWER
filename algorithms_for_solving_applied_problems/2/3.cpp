#include <iostream>
#include <algorithm>

using namespace std;

size_t factorize(size_t _number) {
	size_t m = static_cast<size_t>(sqrt(_number));
	size_t x = 0;
	while (true)
	{
		double buffer_number = sqrt(pow(m + x, 2) - _number);
		if (static_cast<size_t>(buffer_number) == buffer_number) {
			return static_cast<size_t>(buffer_number);
		}
		x += 1;
	}
}

int main() {
	int64_t number = 0;
	cin >> number;
	cout << factorize(number);
}
