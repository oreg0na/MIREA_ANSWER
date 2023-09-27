# 3.2. Кто-то рэп читал, кто-то рисовал граффити

```cpp
#include <iostream>
#include <vector>

using namespace std;

template <class _Type>
ostream& operator << (ostream& _stream, vector<vector<_Type>> _matrix) {
	for (auto& column : _matrix) {
		for (auto& value : column) cout << value << ' ';
		cout << endl;
	}
	return _stream;
}

int main() {
	size_t matrix_size = 0;
	cin >> matrix_size;
	vector<vector<size_t>> matrix;
	matrix.reserve(matrix_size);
	for (auto i = 0ull; i < matrix_size; i++) {
		matrix.push_back({});
		for (auto j = 0ull; j < matrix_size; j++) {
			matrix[i].reserve(matrix_size);
			matrix[i].push_back(0);
		}
	}

	for (auto i = 0ull; i < matrix_size; i++) {
		for (auto j = 0ull; j < matrix_size; j++) {
			if (i == (matrix_size - j - 1)) matrix[i][j] = 1;
			if ((matrix_size - j - 1) < i) matrix[i][j] = 2;
		}
	}

	cout << matrix;
}
```