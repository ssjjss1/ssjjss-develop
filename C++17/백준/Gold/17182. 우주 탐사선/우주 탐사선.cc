#include <bits/stdc++.h>
using namespace std;
const int inf = 1e8 + 4;
int n, m;
int ans = inf;
int d[14][14];
int visited[14];
void f(int x, int y, int cnt) {
    if (ans < y) return;
    if (cnt == n) {
        ans = min(ans, y);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]){
            visited[i] = 1;
            f(i, y + d[x][i], cnt + 1);
            visited[i] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    visited[m] = 1;
    f(m, 0, 1);
    cout << ans;
}