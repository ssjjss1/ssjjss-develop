#include<iostream>
#include<algorithm>
using namespace std;
int n;
int d[504][504];
int dp[504][504];
const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
int f(int x, int y) {
    if (dp[x][y]) return dp[x][y];
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && d[xx][yy] > d[x][y]) {
            dp[x][y] = max(dp[x][y], f(xx, yy) + 1);
        }
    }
    return dp[x][y];
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans = max(ans, f(i, j));
        }
    }
    cout << ans;
}