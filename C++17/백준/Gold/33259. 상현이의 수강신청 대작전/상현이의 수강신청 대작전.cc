#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m;
int dp[5004][5004];
pair<int, int> trace[5004][5004];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    vector<pair<int, int>> v(n + 1);

    for (int i = 1; i <= n; i++) {
        int p, c;
        cin >> p >> c;
        v[i] = {p, c};
    }

    memset(dp, -INF, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        int p = v[i].first, c = v[i].second;
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            trace[i][j] = {i - 1, j};
            if (j >= c && dp[i - 1][j - c] + p > dp[i][j]) {
                dp[i][j] = dp[i - 1][j - c] + p;
                trace[i][j] = {i - 1, j - c};
            }
        }
    }

    int mx = -INF, idx = -1;
    for (int j = 1; j <= m; j++) {
        if (dp[n][j] > mx) {
            mx = dp[n][j];
            idx = j;
        }
    }
    
    if (mx <= 0) cout << -1;
    else {
        vector<int> ans;
        pair<int, int> cx = {n, idx};
        while (cx.first > 0) {
            auto i = cx.first, j = cx.second;
            if (trace[i][j].second != j) ans.push_back(i); 
            cx = trace[i][j];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto x : ans) cout << x << " ";
    }
}