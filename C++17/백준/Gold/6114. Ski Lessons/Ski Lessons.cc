#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9 + 7;
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, s, n;
    cin >> t >> s >> n;

    vector<pair<int, int>> C[10004];

    vector<int> level(104, INF);

    for (int i = 0; i < s; i++) {
        int m, l, a;
        cin >> m >> l >> a;
        C[m].push_back({ l, a });  
    }

    for (int i = 0; i < n; i++) {
        int c, d;
        cin >> c >> d;
        level[c] = min(level[c], d);
    }

    int mn = INF;
    for (int i = 1; i <= 100; i++) {
        mn = min(level[i], mn);
        level[i] = mn;
    }

    vector<int> dp(t + 4, -1), skill(t + 4, 1);
    dp[0] = 0;

    for (int i = 0; i <= t; i++) {
        if (dp[i] == -1) continue;

        int cs = skill[i];
        int mnTime = level[cs];

        if (mnTime != INF && i + mnTime <= t) {
            if (dp[i + mnTime] < dp[i] + 1) {
                dp[i + mnTime] = dp[i] + 1;
                skill[i + mnTime] = cs;
            }
            else if (dp[i + mnTime] == dp[i] + 1) {
                skill[i + mnTime] = max(skill[i + mnTime], cs);
            }
        }

        for (auto [l, a] : C[i]) {
            if (i + l > t) continue;
            if (dp[i + l] < dp[i]) {
                dp[i + l] = dp[i];
                skill[i + l] = a;
            } else if (dp[i + l] == dp[i]) {
                skill[i + l] = max(skill[i + l], a);
            }
        }

        if (i + 1 <= t && dp[i + 1] < dp[i]) {
            dp[i + 1] = dp[i];
            skill[i + 1] = skill[i];
        } else if (i + 1 <= t && dp[i + 1] == dp[i]) {
            skill[i + 1] = max(skill[i + 1], skill[i]);
        }
    }

    cout << *max_element(dp.begin(), dp.end());
}