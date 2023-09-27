#include <iostream>
#include <algorithm>
#include <string>

int main() {
	std::string x, y, y_rev;
	std::cin >> x >> y;
	y_rev = y;
	std::reverse(y_rev.begin(), y_rev.end());
	if (x.find(y) != std::string::npos || x.find(y_rev) != std::string::npos) {
		std::cout << "yes";
	}
	else {
		std::cout << "no";
	}
}
