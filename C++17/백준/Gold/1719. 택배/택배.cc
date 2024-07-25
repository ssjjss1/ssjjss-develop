#include<iostream>
using namespace std;
const int inf = 1e9+4;
int n, m;
int a[404][404], d[404][404];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = inf;
        }
    }
    for (int i = 1, x, y, z; i <= m; i++) {
        cin >> x >> y >> z;
        d[x][y] = z, d[y][x] = z;
        a[x][y] = y, a[y][x] = x;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    a[i][j] = a[i][k];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) cout << "- ";
            else cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}