#include <iostream>
using namespace std;
const int mod = 1000000009;
int dp[1004][1004];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    dp[0][0] = 1; 
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            if (i - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
            if (i - 2 >= 0) dp[i][j] = (dp[i][j] + dp[i - 2][j - 1]) % mod;
            if (i - 3 >= 0) dp[i][j] = (dp[i][j] + dp[i - 3][j - 1]) % mod;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << dp[n][m] << "\n";
    }
}