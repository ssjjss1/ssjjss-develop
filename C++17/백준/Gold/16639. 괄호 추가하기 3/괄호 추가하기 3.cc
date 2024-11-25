#include <bits/stdc++.h>
using namespace std;
int n;
long long mx_dp[24][24], mn_dp[24][24];
long long calculate(long long a, long long b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return 0;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> num(n / 2 + 1);
    vector<char> sign(n / 2);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) cin >> num[i / 2];
        else cin >> sign[i / 2];
    }
    for (int i = 0; i <= n / 2; i++) {
        mx_dp[i][i] = num[i];
        mn_dp[i][i] = num[i];
    }
    for (int len = 1; len <= n / 2; len++) {
        for (int i = 0; i + len <= n / 2; i++) {
            int j = i + len;
            mx_dp[i][j] = INT_MIN;
            mn_dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                long long mx1 = calculate(mx_dp[i][k], mx_dp[k + 1][j], sign[k]);
                long long mx2 = calculate(mx_dp[i][k], mn_dp[k + 1][j], sign[k]);
                long long mn1 = calculate(mn_dp[i][k], mx_dp[k + 1][j], sign[k]);
                long long mn2 = calculate(mn_dp[i][k], mn_dp[k + 1][j], sign[k]);
                mx_dp[i][j] = max({mx_dp[i][j], mx1, mx2, mn1, mn2});
                mn_dp[i][j] = min({mn_dp[i][j], mx1, mx2, mn1, mn2});
            }
        }
    }
    cout << mx_dp[0][n / 2];
}
