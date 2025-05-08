#include <bits/stdc++.h>
using namespace std;

int n, m;
int d[104][304];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> d[i][j];
        }
    }

    vector<pair<int, int>> v[304];

    for (int i = 1; i <= n; i++) {
        int cx = 0;
        for (int j = 1; j <= m; j++) {
            int s = cx;
            int e = cx + d[i][j];

            v[j].push_back({ s , 1 });
            v[j].push_back({ e, -1 });
            cx = e;
        }
    }

    for (int i = 1; i <= m; i++) {
        sort(v[i].begin(), v[i].end());
        int cx = 0, ans = 0;
        for (auto [_, cnt] : v[i]) {
            cx += cnt;
            ans = max(ans, cx);
        }
        cout << ans << " ";
    }
}