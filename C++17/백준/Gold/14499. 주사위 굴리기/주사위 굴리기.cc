#include <iostream>
using namespace std;
int n, m, x, y, cnt;
int d[24][24];
int dice[7];// 1: up, 2: front, 3: right, 4: left, 5: back, 6: down(bottom)
pair<int, int> p[5] = { {0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
void f(int dir) {
    int t[7];
    for (int i = 1; i <= 6; i++) t[i] = dice[i];
    if (dir == 1) {
        dice[1] = t[4];
        dice[3] = t[1];
        dice[6] = t[3];
        dice[4] = t[6];
    }
    else if (dir == 2) {
        dice[1] = t[3];
        dice[4] = t[1];
        dice[6] = t[4];
        dice[3] = t[6];
    }
    else if (dir == 3) {
        dice[1] = t[5];
        dice[5] = t[6];
        dice[6] = t[2];
        dice[2] = t[1];
    }
    else if (dir == 4) {
        dice[1] = t[2];
        dice[5] = t[1];
        dice[6] = t[5];
        dice[2] = t[6];
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> x >> y >> cnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d[i][j];
        }
    }
    for (int i = 1, dir; i <= cnt; i++) {
        cin >> dir;
        int xx = x + p[dir].first;
        int yy = y + p[dir].second;
        if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
        x = xx;
        y = yy;
        f(dir);
        if (d[x][y] == 0) {
            d[x][y] = dice[6];
        }
        else {
            dice[6] = d[x][y];
            d[x][y] = 0;
        }
        cout << dice[1] << "\n";
    }
}