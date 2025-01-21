#include <bits/stdc++.h>
#define INF 100004
using namespace std;
typedef long long ll;
int n, m, cnt, opt;
ll t[INF * 4], lazy[INF * 4], nt[INF * 4], nlazy[INF * 4];
vector<int> v[INF];
int s[INF], e[INF];

void propagation(ll seg[], ll lazy[], int node, int l, int r) {
    if (lazy[node]) {
        seg[node] += (r - l + 1) * lazy[node];
        if (l != r) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(ll seg[], ll lazy[], int node, int l, int r, int x, int y, ll val) {
    propagation(seg, lazy, node, l, r);
    if (y < l || r < x) return;
    if (x <= l && r <= y) {
        lazy[node] += val;
        propagation(seg, lazy, node, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(seg, lazy, node * 2, l, mid, x, y, val);
    update(seg, lazy, node * 2 + 1, mid + 1, r, x, y, val);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll query(ll seg[], ll lazy[], int node, int l, int r, int x, int y) {
    propagation(seg, lazy, node, l, r);
    if (y < l || r < x) return 0;
    if (x <= l && r <= y) return seg[node];
    int mid = (l + r) / 2;
    return query(seg, lazy, node * 2, l, mid, x, y) + query(seg, lazy, node * 2 + 1, mid + 1, r, x, y);
}

void find(int idx) {
    s[idx] = ++cnt;
    for (auto i : v[idx]) find(i);
    e[idx] = cnt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x != -1) {
            v[x].push_back(i);
        }
    }
    
    find(1);

    for (int i = 1; i <= m; i++) {
        int mode; cin >> mode;
        if (mode == 1) {
            int x, w; cin >> x >> w;
            if (opt % 2 == 0) {
                update(t, lazy, 1, 1, n, s[x], e[x], w);
            } else {
                update(nt, nlazy, 1, 1, n, s[x], s[x], w);
            }
        } else if (mode == 2) {
            int x; cin >> x;
            ll res1 = query(t, lazy, 1, 1, n, s[x], s[x]);
            ll res2 = query(nt, nlazy, 1, 1, n, s[x], e[x]);
            cout << res1 + res2 << '\n';
        } else {
            opt++;
        }
    }
}