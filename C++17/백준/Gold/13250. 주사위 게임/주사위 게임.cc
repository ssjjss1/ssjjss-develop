#include <bits/stdc++.h>
using namespace std;

int n;
long double dp[1000006];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) dp[i] += (dp[i - j] + 1) / 6.0;
            else dp[i] += 1.0 / 6.0;
        }
    }
    
    cout << fixed << setprecision(18) << dp[n];
}