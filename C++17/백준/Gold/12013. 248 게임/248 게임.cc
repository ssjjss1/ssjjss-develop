#include <bits/stdc++.h>
using namespace std;
int n, ans;
int dp[254][254];
int main() {
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> dp[i][i];
        ans = max(dp[i][i], ans);
    }
    for (int len = 2; len <= n; len++) { 
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1; 
            dp[i][j] = 0; 
            for (int k = i; k < j; k++) {
                if (dp[i][k] == dp[k + 1][j] && dp[i][k] != 0) { 
                    dp[i][j] = max(dp[i][j], dp[i][k] + 1);
                }
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans;
}