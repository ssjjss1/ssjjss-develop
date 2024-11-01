#include <bits/stdc++.h>
using namespace std;
int n, k;
int sum[14][2004], dp[2004];
vector<int> v[14];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        v[y].push_back(x);
    }
    for (int i = 1; i <= 10; i++) sort(v[i].rbegin(), v[i].rend()); 
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            sum[i][j + 1] = sum[i][j] + v[i][j] + 2 * j; 
        }
    }
    for (int i = 1; i <= 10; i++) {
        if (v[i].size()) {
            for (int cnt = k; cnt >= 1; cnt--) {
                for (int j = 1; j <= v[i].size() && j <= cnt; j++) {
                    dp[cnt] = max(dp[cnt], dp[cnt - j] + sum[i][j]);
                }
            }
        }
    }
    cout << dp[k];
}