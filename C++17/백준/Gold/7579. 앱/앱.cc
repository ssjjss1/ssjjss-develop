#include<iostream>
#include<algorithm>
using namespace std;
int N, M;   
long long m[104], c[104], dp[10004]; 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> m[i];     
    for (int i = 1; i <= N; i++) cin >> c[i];
    fill(dp, dp + 10004, 0);
    for (int i = 1; i <= N; i++) {
        for (int j = 10000; j >= c[i]; j--) {
            dp[j] = max(dp[j], dp[j - c[i]] + m[i]);  
        }
    }
    int ans = 1e9;  
    for (int i = 0; i <= 10000; i++) {
        if (dp[i] >= M) ans = min(ans, i);
    }
    cout << ans;
}