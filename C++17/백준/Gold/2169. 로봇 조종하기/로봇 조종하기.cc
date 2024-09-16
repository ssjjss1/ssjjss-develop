#include <iostream>
using namespace std;
int n, m;
int d[1004][1004], dp[1004][1004];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d[i][j];
        }
    }
    dp[0][0] = d[0][0];
    for (int j = 1; j < m; j++) dp[0][j] = dp[0][j - 1] + d[0][j];
    for (int i = 1; i < n; i++) {
        int l[1004], r[1004];
        l[0] = dp[i - 1][0] + d[i][0];
        for (int j = 1; j < m; j++) {
            l[j] = max(l[j - 1], dp[i - 1][j]) + d[i][j];
        }
        r[m - 1] = dp[i - 1][m - 1] + d[i][m - 1];
        for (int j = m - 2; j >= 0; j--) {
            r[j] = max(r[j + 1], dp[i - 1][j]) + d[i][j];
        }
        for (int j = 0; j < m; j++) dp[i][j] = max(l[j], r[j]);
    }
    cout << dp[n - 1][m - 1];
}