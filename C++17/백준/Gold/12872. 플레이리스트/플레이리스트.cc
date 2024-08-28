#include<iostream>
using namespace std;
int n, m, p;
long long dp[104][104];
const int mod = 1000000007;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> p;
    dp[0][0] = 1;
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i-1][j-1] * (n - (j-1))) % mod;
            if (j > m) dp[i][j] = (dp[i][j] + dp[i-1][j] * (j - m)) % mod;
        }
    }
    cout << dp[p][n];
}
