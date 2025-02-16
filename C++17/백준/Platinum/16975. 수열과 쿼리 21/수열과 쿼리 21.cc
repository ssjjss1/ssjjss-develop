#include <bits/stdc++.h>
#define INF 100004
using namespace std;

int n, m;
long long d[INF], t[INF * 4], lazy[INF * 4];

void propagate(int node, int x, int y) {
    if (lazy[node] != 0) {
        t[node] += (y - x + 1) * lazy[node];
        if (x != y) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void Init(int node, int x, int y) {
    if (x == y) {
        t[node] = d[x];
        return;
    }
    int mid = (x + y) / 2;
    Init(node * 2, x, mid);
    Init(node * 2 + 1, mid + 1, y);
    t[node] = t[node * 2] + t[node * 2 + 1];
}

void update(int node, int x, int y, int l, int r, long long val) {
    propagate(node, x, y);
    
    if (y < l || x > r) return;
    if (l <= x && y <= r) {
        lazy[node] += val;
        propagate(node, x, y);
        return;
    }
    
    int mid = (x + y) / 2;
    update(node * 2, x, mid, l, r, val);
    update(node * 2 + 1, mid + 1, y, l, r, val);
    t[node] = t[node * 2] + t[node * 2 + 1];
}

long long query(int node, int x, int y, int idx) {
    propagate(node, x, y);
    
    if (x == y) return t[node];

    int mid = (x + y) / 2;
    if (idx <= mid) return query(node * 2, x, mid, idx);
    else return query(node * 2 + 1, mid + 1, y, idx);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    Init(1, 1, n);

    cin >> m;
    while (m--) {
        int mode;
        cin >> mode;
        if (mode == 1) {
            int i, j, k;
            cin >> i >> j >> k;
            update(1, 1, n, i, j, k);
        } else {
            int x;
            cin >> x;
            cout << query(1, 1, n, x) << '\n';
        }
    }
}