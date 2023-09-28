#include <iostream>
#include <vector>

using namespace std;

int main() {
	size_t size = 0;
	cin >> size;
	vector<size_t> values;
	size_t result = 0;
	for (size_t i = 0; i < size; i++) {
		size_t value = 0;
		cin >> value;
		values.push_back(value);
	}
	for (size_t i = 0; i < values.size(); i++) {
		if (i == 0) { if (values[i + 1] < values.front()) result += 1; }
		else if (i == values.size() - 1) { if (values.back() > values[values.size() - 2]) result += 1; }
		else { if (values[i - 1] + values[i + 1] <= values[i]) result += 1; }
	}
	cout << result << endl;
}