#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

void Init(int n) {
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;
}

int Find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y) parent[x] = y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (true) {
        int n, m, k;
        cin >> n >> m >> k;
        if (n == 0 && m == 0 && k == 0) return 0;

        parent.resize(n + 1);
        vector<vector<int>> red(n + 1), blue(n + 1);

        for (int i = 0; i < m; i++) {
            char c;
            int f, t;
            cin >> c >> f >> t;
            if (c == 'B') {
                blue[f].push_back(t);
                blue[t].push_back(f);
            } else {
                red[f].push_back(t);
                red[t].push_back(f);
            }
        }

        Init(n);
        int blue_mn = 0, blue_mx = 0;

        for (int i = 1; i <= n; i++) {
            for (auto cx : red[i]) {
                if (Find(i) != Find(cx)) {
                    Union(i, cx);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (auto cx : blue[i]) {
                if (Find(i) != Find(cx)) {
                    Union(i, cx);
                    blue_mn++;
                }
            }
        }

        Init(n);

        for (int i = 1; i <= n; i++) {
            for (auto cx : blue[i]) {
                if (Find(i) != Find(cx)) {
                    Union(i, cx);
                    blue_mx++;
                }
            }
        }

        if (blue_mn <= k && k <= blue_mx) cout << "1\n";
        else cout << "0\n";
    }
}