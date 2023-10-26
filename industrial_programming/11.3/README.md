# В дверь постучали

``` cpp
#include <fstream>
#include <vector>

void fill_spiral(std::vector<std::vector<int>>& matrix, int n) {
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int x = 0, y = 0, d = 0;
    for (int i = 1; i <= n * n; ++i) {
        matrix[x][y] = i;
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n || matrix[nx][ny]) {
            d = (d + 1) % 4;
            nx = x + dx[d];
            ny = y + dy[d];
        }
        x = nx;
        y = ny;
    }
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    if (!input.is_open() || !output.is_open()) {
        return 1;
    }

    int n;
    input >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    fill_spiral(matrix, n);

    for (const auto& row : matrix) {
        for (const auto& cell : row) {
            output << cell;
        }
        output << '\n';
    }

    return 0;
}
```
