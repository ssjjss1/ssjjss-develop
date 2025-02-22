#include <bits/stdc++.h>
#define INF 100004
using namespace std;

int t, n, m;
pair<int, int> tree[INF * 4];
int d[INF];

void Init(int node, int l, int r) {
    if (l == r) {
        tree[node] = { l, l };
        return;
    }
    int mid = (l + r) / 2;
    Init(node * 2, l, mid);
    Init(node * 2 + 1, mid + 1, r);
    tree[node] = { min(tree[node * 2].first, tree[node * 2 + 1].first),
                  max(tree[node * 2].second, tree[node * 2 + 1].second) };
}

void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        tree[node] = { val, val };
        return;
    }
    int middle = (l + r) / 2;
    if (idx <= middle) update(node * 2, l, middle, idx, val);
    else update(node * 2 + 1, middle + 1, r, idx, val);
    tree[node] = { min(tree[node * 2].first, tree[node * 2 + 1].first),
                  max(tree[node * 2].second, tree[node * 2 + 1].second) };
}

pair<int, int> query(int node, int l, int r, int a, int b) {
    if (a > r || b < l) return { INF, -INF };
    if (a <= l && r <= b) return tree[node];
    int middle = (l + r) / 2;
    auto left = query(node * 2, l, middle, a, b);
    auto right = query(node * 2 + 1, middle + 1, r, a, b);
    return { min(left.first, right.first), max(left.second, right.second) };
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        Init(1, 0, n - 1);
        for (int i = 0; i < n; i++) d[i] = i;
        while (m--) {
            int q, a, b;
            cin >> q >> a >> b;
            if (q == 0) {
                update(1, 0, n - 1, b, d[a]);
                update(1, 0, n - 1, a, d[b]);
                swap(d[a], d[b]);
            }
            else {
                auto [mn, mx] = query(1, 0, n - 1, a, b);
                cout << ((mn == a && mx == b) ? "YES" : "NO") << "\n";
            }
        }
    }
}