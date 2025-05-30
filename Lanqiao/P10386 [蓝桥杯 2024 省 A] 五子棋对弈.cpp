#include <bits/stdc++.h>
using namespace std;

int ans = 0;
bool check(const vector<int>& grid) {
    vector<vector<int>> a(5, vector<int>(5));
    for (int i = 0; i < 25; ++i) {
        a[i / 5][i % 5] = grid[i];
    }

    int dx[4] = {0, 1, 1, 1};
    int dy[4] = {1, 0, 1, -1};

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int d = 0; d < 4; ++d) {
                int x = i, y = j, count = 0;
                while (x >= 0 && x < 5 && y >= 0 && y < 5 &&
                       a[x][y] == a[i][j]) {
                    count++;
                    if (count == 5) return 1;
                    x += dx[d];
                    y += dy[d];
                }
            }
        }
    }
    return 0;
}

int main() {
    vector<int> grid(25, 1);
    for (int i = 0; i < 13; ++i) grid[i] = 0;

    sort(grid.begin(), grid.end());

    do {
        if (!check(grid)) {
            ans++;
        }
    } while (next_permutation(grid.begin(), grid.end()));

    cout << ans << endl;
    return 0;
}
