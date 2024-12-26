#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        int mx = 0; 
        vector<vector<char>> v(n + 4, vector<char>(n + 4, '#'));
        vector<vector<int>> dp(n + 4, vector<int>(n + 4, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> v[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (v[i][j] != '#') {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                    mx = max(mx, dp[i][j]);
                }
            }
        }
        cout << mx * mx << "\n";
    }
}