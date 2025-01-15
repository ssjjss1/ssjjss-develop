#include<bits/stdc++.h>
#define INF 500004
using namespace std;
int n, m, cnt;

vector<int> v[INF];
long long cost[INF], t[INF * 4], lazy[INF * 4];
int s[INF], e[INF];

void propagation(int node, int l, int r) {
    if (lazy[node]) {
        t[node] += lazy[node] * (r - l + 1);
        if (l != r) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int l, int r, int x, int y, int val) {
    propagation(node, l, r);
    if (y < l || r < x) return;
    if (x <= l && r <= y) {
        lazy[node] += val;
        propagation(node, l, r);
        return;
    }
    int middle = (l + r) / 2;
    update(node * 2, l, middle, x, y, val);
    update(node * 2 + 1, middle + 1, r, x, y, val);
    t[node] = t[node * 2] + t[node * 2 + 1];
}

long long query(int node, int l, int r, int idx) {
    propagation(node, l, r);
    if (l == r) return t[node];
    int middle = (l + r) / 2;
    if (idx <= middle) return query(node * 2, l, middle, idx);
    else return query(node * 2 + 1, middle + 1, r, idx);
}

void find_boss(int idx) {
    s[idx] = ++cnt;
    for (int i : v[idx]) find_boss(i);
    e[idx] = cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int boss;
        if (i == 1) cin >> cost[i];
        else {
            cin >> cost[i] >> boss;
            v[boss].push_back(i);
        }
    }

    find_boss(1);

    for (int i = 1; i <= n; i++) update(1, 1, n, s[i], s[i], cost[i]);

    for (int i = 1; i <= m; i++) {
        char c;
        cin >> c;

        if (c == 'p') {
            int x, y;
            cin >> x >> y;
            update(1, 1, n, s[x] + 1, e[x], y);
        } else {
            int x;
            cin >> x;
            cout << query(1, 1, n, s[x]) << "\n";
        }
    }
}
