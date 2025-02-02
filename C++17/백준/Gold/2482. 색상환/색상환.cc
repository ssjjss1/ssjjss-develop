#include<bits/stdc++.h>
#define MOD 1000000003 
using namespace std;

int n, k;
long long dp[1004][1004];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    
    if (n < k * 2) {
        cout << 0;
        return 0;
    }
    
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
        dp[i][1] = i;
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
        }
    }
    
    cout << (dp[n - 1][k] + dp[n - 3][k - 1]) % MOD;
}