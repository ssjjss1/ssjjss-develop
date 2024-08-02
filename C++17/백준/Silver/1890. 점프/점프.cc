#include<iostream>
using namespace std;
int n, d[104][104];
long long dp[104][104];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }
    dp[1][1] = 1; 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] != 0 && d[i][j] != 0) { 
                if (i + d[i][j] <= n) dp[i + d[i][j]][j] += dp[i][j];
                if (j + d[i][j] <= n) dp[i][j + d[i][j]] += dp[i][j];
            }
        }
    }
    cout << dp[n][n];
}