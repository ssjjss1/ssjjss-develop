#include <iostream>
using namespace std;
int n;
int d[24][24], dp[24][24][4];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }
    dp[1][2][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 3; j <= n; j++) { 
            if (d[i][j] == 1) continue;
            dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
            dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
            if (d[i - 1][j] == 0 && d[i][j - 1] == 0) {
                dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
            }
        }
    }
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
}