#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int inf = 1e9;
int n, m;
int d[104][104];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = inf;
        }
    }
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        d[x][y] = 1;
        d[y][x] = 1; 
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int mn = inf;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) sum += d[i][j];
        if (sum < mn) {
            mn = sum;
            ans = i;
        }
    }
    cout << ans;
}