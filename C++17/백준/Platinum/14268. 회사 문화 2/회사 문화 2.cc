#include <bits/stdc++.h>
#define INF 100007
using namespace std;

int n, m, cnt;
long long lazy[INF * 4], t[INF * 4];
vector<int> v[INF];
int s[INF], e[INF];

void propagate(int node, int l, int r) {
    if (lazy[node]) {
        t[node] += lazy[node];
        if (l != r) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int l, int r, int x, int y, int diff) {
    propagate(node, l, r);
    if (y < l || r < x) return;
    if (x <= l && r <= y) {
        lazy[node] += diff;
        propagate(node, l, r);
        return;
    }
    int middle = (l + r) / 2;
    update(node * 2, l, middle, x, y, diff);
    update(node * 2 + 1, middle + 1, r, x, y, diff);
    t[node] = t[node * 2] + t[node * 2 + 1];
}

long long query(int node, int l, int r, int idx) {
    propagate(node, l, r);
    if (idx < l || r < idx) return 0;
    if (l == r) return t[node];
    int middle = (l + r) / 2;
    return query(node * 2, l, middle, idx) + query(node * 2 + 1, middle + 1, r, idx);
}

void findEmployee(int idx) {
    s[idx] = ++cnt;
    for (auto i : v[idx]) findEmployee(i);
    e[idx] = cnt;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x != -1) v[x].push_back(i);
    }

    findEmployee(1);

    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        if (x == 1) {
            int y, w; cin >> y >> w;
            update(1, 1, n, s[y], e[y], w);
        } else {
            int y; cin >> y;
            cout << query(1, 1, n, s[y]) << "\n";
        }
    }
}