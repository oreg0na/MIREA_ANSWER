#include <iostream>
#include <vector>

using namespace std;

struct mushroom_coordinate {
	int64_t x = 0, y = 0;

	constexpr bool operator==(mushroom_coordinate& _m) {
		return _m.x == x && _m.y == y ? true : false;
	}
};

bool is_mushroom(mushroom_coordinate _coordinate, vector<mushroom_coordinate>& _coordinates) {
	for (auto& coordinate : _coordinates) {
		if (coordinate == _coordinate) return true;
	}

	return false;
}

size_t count_mushroom_near(mushroom_coordinate _coordinate, vector<mushroom_coordinate>& _coordinates) {
	size_t counts = 0;
	for (auto i = _coordinate.x - 1; i <= _coordinate.x + 1; i++) {
		for (auto j = _coordinate.y - 1; j <= _coordinate.y + 1; j++) {
			if (is_mushroom({ i + 1, j + 1 }, _coordinates)) counts += 1;
		}
	}
	return counts;
}

int main() {
	size_t height_matrix = 0, width_matrix = 0, count_mushroom = 0;
	cin >> height_matrix >> width_matrix >> count_mushroom;

	vector<mushroom_coordinate> mushroom_coordinates = {};
	for (auto i = 0ull; i < count_mushroom; i++) {
		int64_t mushroom_x = 0, mushroom_y = 0;
		cin >> mushroom_x >> mushroom_y;
		mushroom_coordinates.push_back({ mushroom_x, mushroom_y });
	}

	for (auto i = 0ll; i < height_matrix; i++) {
		for (auto j = 0ll; j < width_matrix; j++) {
			if (is_mushroom({ i + 1, j + 1 }, mushroom_coordinates)) cout << '*';
			else cout << count_mushroom_near({ i, j }, mushroom_coordinates);
		} 
		cout << endl;
	}
}
