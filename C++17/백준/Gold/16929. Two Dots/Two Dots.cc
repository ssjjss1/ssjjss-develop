#include <iostream>
#include <vector>
using namespace std;
int n, m;
char c[54][54];
int visited[54][54];
const int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
bool f(int x, int y, int X, int Y, char t) {
    if (visited[x][y]) return 1;
    visited[x][y] = 1;
    for (int d = 0; d < 4; d++) {
        int xx = x + dx[d];
        int yy = y + dy[d];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m || (xx == X && yy == Y)) continue;
        if (c[xx][yy] == t) {
            if (f(xx, yy, x, y, t)) return 1;
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                if (f(i, j, 0, 0, c[i][j])) {
                    cout << "Yes" ;
                    return 0;
                }
            }
        }
    }
    cout << "No" ;
}