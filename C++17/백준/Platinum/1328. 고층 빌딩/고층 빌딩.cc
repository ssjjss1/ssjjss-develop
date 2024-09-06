#include<iostream>
using namespace std;
const int mod = 1000000007;
int n, m, k;
long long dp[104][104][104];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    dp[1][1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int l = 1; l <= m; l++) {
            for (int r = 1; r <= k; r++) {
                dp[i][l][r] = (dp[i - 1][l - 1][r] + dp[i - 1][l][r - 1] + (dp[i - 1][l][r] * (i - 2)) % mod) % mod;
            }
        }
    }
    cout << dp[n][m][k] % mod;
}