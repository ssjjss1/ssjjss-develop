#include <bits/stdc++.h>
#define pi 3.14159265358979323846

const long long MOD = 1000000000000000000;
const int MAX_J = 320;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<long long>> dp(n + 1, vector<long long>(MAX_J, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = MAX_J - 1; j >= 0; j--) {
            double val = i - pi * j;
            if (0 <= val && val <= pi) {
                dp[i][j] = 1;
            } else {
                long long a = (i > 0 ? dp[i - 1][j] : 0);
                long long b = (j + 1 < MAX_J ? dp[i][j + 1] : 0);
                dp[i][j] = (a + b) % MOD;
            }
        }
    }

    cout << dp[n][0];
}