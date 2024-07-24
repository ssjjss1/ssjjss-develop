#include<iostream>
using namespace std;
const int inf = 1e9 + 4;
int n, m, r;
int a[104], d[104][104];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> r;
    fill(&d[0][0], &d[0][0] + 104 * 104, inf);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i][i] = 0;
    }
    for (int i = 1, x, y, z; i <= r; i++) {
        cin >> x >> y >> z;
        d[x][y] = z;
        d[y][x] = z;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int mx1 = 0;
        for (int j = 1; j <= n; j++) {
            if (d[i][j] <= m) mx1 += a[j];
        }
        mx = max(mx, mx1);
    }
    cout << mx;
}