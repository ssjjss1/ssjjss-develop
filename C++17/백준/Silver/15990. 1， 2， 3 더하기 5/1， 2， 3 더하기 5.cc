#include <iostream>
using namespace std;
const int mod = 1000000009;
int t;
int dp[100001][4];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    for (int i = 4; i <= 100000; i++) {
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % mod;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % mod;
    }
    while (t--) {
        int n;
        cin >> n;
        cout << ((dp[n][1] + dp[n][2]) % mod + dp[n][3]) % mod << '\n';
    }
}