#include <bits/stdc++.h>
using namespace std;
int n, m, a, d;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) cin >> s[i];
    cin >> a >> d;

    int limit = (n + d - 1) / d;
    vector<vector<int>> dp(limit + 1, vector<int>(n + d + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= limit; j++) {
            if (j != 0 && dp[j][i - 1] == 0) continue;
            dp[j][i] = max(dp[j][i], dp[j][i - 1] + s[i]);
            if (j != limit) {
                dp[j + 1][i + d - 1] = max(dp[j + 1][i + d - 1], dp[j][i - 1] + a);
            }
        }
    }

    for (int i = 0; i <= limit; i++) {
        if (*max_element(dp[i].begin(), dp[i].end()) >= m) {
            cout << i << "\n";
            return 0;
        }
    }

    cout << -1;
}