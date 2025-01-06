#include<bits/stdc++.h>
using namespace std;

int n;
long long t[404040], lazy[404040];

void lazy_update(int node, int l, int r) {
    if (lazy[node]) {
        t[node] += lazy[node];
        if (l != r) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int l, int r, int x, int y, int cnt) {
    lazy_update(node, l, r);
    if (r < x || y < l) return;
    if (x <= l && r <= y) {
        lazy[node] += cnt;
        lazy_update(node, l, r);
        return;
    }
    int middle = (l + r) / 2;
    update(node * 2, l, middle, x, y, cnt);
    update(node * 2 + 1, middle + 1, r, x, y, cnt);
    t[node] = t[node * 2] + t[node * 2 + 1];
}

long long query(int node, int l, int r, int idx) {
    lazy_update(node, l, r);
    if (r < idx || idx < l) return 0;
    if (l == r) return t[node];
    
    int middle = (l + r) / 2;
    return query(node * 2, l, middle, idx) + query(node * 2 + 1, middle + 1, r, idx);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        long long left = query(1, 1,1e5, x), right = query(1, 1, 1e5, y);
        cout << left + right << "\n";
        update(1, 1, 1e5, x, x, -left);
        update(1, 1, 1e5, y, y, -right);
        if (x + 1 < y) update(1, 1, 1e5, x + 1, y - 1, 1);
    }
}
