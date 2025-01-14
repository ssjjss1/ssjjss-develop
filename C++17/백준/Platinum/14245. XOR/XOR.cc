#include<bits/stdc++.h>
#define INF 500004
using namespace std;
int n, m;
long long d[INF], t[INF * 4], lazy[INF * 4];

void propagation(int node, int l, int r) {
    if (lazy[node]) {
        t[node] ^= lazy[node] * (r - l + 1);
        if (l != r) {
            lazy[node * 2] ^= lazy[node];
            lazy[node * 2 + 1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int l, int r, int x, int y, long long val) {
    propagation(node, l, r);
    if (x > r || y < l) return;
    if (x <= l && r <= y) {
        lazy[node] ^= val;
        propagation(node, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(node * 2, l, mid, x, y, val);
    update(node * 2 + 1, mid + 1, r, x, y, val);
    t[node] = t[node * 2] ^ t[node * 2 + 1];
}

long long query(int node, int l, int r, int x) {
    propagation(node, l, r);
    if (x < l || x > r) return 0;
    if (l == r) return t[node];
    int mid = (l + r) / 2;
    if (x <= mid) return query(node * 2, l, mid, x);
    else return query(node * 2 + 1, mid + 1, r, x);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int i = 0; i < n; i++) update(1, 0, n - 1, i, i, d[i]);
    cin >> m;
    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int a, b, c;
            cin >> a >> b >> c;
            update(1, 0, n - 1, a, b, c);
        } else {
            int a;
            cin >> a;
            cout << query(1, 0, n - 1, a) << '\n';
        }
    }
}
