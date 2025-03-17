#include <bits/stdc++.h>
#define INF 1e9+7
using namespace std;

pair<int, int> t[200004]; 

void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        t[node] = {val, val};
        return;
    }

    int middle = (l + r) / 2;
    if (idx <= middle)
        update(node * 2, l, middle, idx, val);
    else
        update(node * 2 + 1, middle + 1, r, idx, val);

    t[node] = {max(t[node * 2].first, t[node * 2 + 1].first),
               min(t[node * 2].second, t[node * 2 + 1].second)};
}

pair<int, int> query(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return {-INF, INF};
    if (ql <= l && r <= qr) return t[node];

    int middle = (l + r) / 2;
    pair<int, int> left = query(node * 2, l, middle, ql, qr);
    pair<int, int> right = query(node * 2 + 1, middle + 1, r, ql, qr);

    return {max(left.first, right.first), min(left.second, right.second)};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(1, 1, n, i, x);
    }

    while (q--) {
        int s, e;
        cin >> s >> e;

        pair<int, int> ans = query(1, 1, n, s, e);
        cout << ans.first - ans.second << "\n";
    }
}