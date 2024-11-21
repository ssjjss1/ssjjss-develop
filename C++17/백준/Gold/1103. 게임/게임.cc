#include<bits/stdc++.h>
using namespace std;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int n, m;
int d[54][54], dp[54][54], visited[54][54];
int dfs(int x, int y) {
    if (x <= 0 || y <= 0 || x > n || y > m || d[x][y] == 0) return -1e9;
    if (visited[x][y]) return -1;
    if (dp[x][y] != -1) return dp[x][y];
    visited[x][y] = 1;
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + d[x][y] * dx[i], ny = y + d[x][y] * dy[i];
        int result = dfs(nx, ny);
        if (result == -1) {
            cout << -1;
            exit(0);
        }
        dp[x][y] = max(dp[x][y], result + 1);
    }
    visited[x][y] = 0;
    return dp[x][y];
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == 'H') d[i][j] = 0;
            else d[i][j] = c - '0';
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans = dfs(1, 1);
    cout << ans;
}