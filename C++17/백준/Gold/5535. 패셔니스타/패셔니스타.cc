#include <bits/stdc++.h>
using namespace std;

struct P {
    int a, b, c;
};

int d[204], dp[204][204];
vector<P> v;
int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> d[i];
    }

    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].a >> v[i].b >> v[i].c;
    }

    memset(dp, -1, sizeof(dp));

    for (int j = 0; j < n; j++) {
        if (v[j].a <= d[1] && d[1] <= v[j].b) {
            dp[1][j] = 0;
        }
    }

    for (int i = 2; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            if (v[j].a <= d[i] && d[i] <= v[j].b) {
                for (int k = 0; k < n; k++) {
                    if (dp[i - 1][k] != -1) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][k] + abs(v[j].c - v[k].c));
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < n; j++) {
        ans = max(ans, dp[m][j]);
    }
    cout << ans;
}