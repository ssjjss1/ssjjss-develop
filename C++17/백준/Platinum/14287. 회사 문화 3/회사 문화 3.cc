#include<bits/stdc++.h>
#define INF 100004
using namespace std;

int n, m, cnt;
vector<int> v[INF];
long long d[INF], t[INF * 4], lazy[INF * 4];
int s[INF], e[INF];

void propagation(int node, int l, int r) {
    if (lazy[node]) {
        t[node] += (r - l + 1) * lazy[node];
        if (l != r) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int l, int r, int x, int val) {
    propagation(node, l, r);
    if (l == r) {
        t[node] += val;
        return;
    }
    int middle = (l + r) / 2;
    if (x <= middle) update(node * 2, l, middle, x, val);
    else update(node * 2 + 1, middle + 1, r, x, val);
    t[node] = t[node * 2] + t[node * 2 + 1];
}

long long query(int node, int l, int r, int x, int y) {
    propagation(node, l, r);
    if (y < l || x > r) return 0;
    if (x <= l && r <= y) return t[node];
    int middle = (l + r) / 2;
    return query(node * 2, l, middle, x, y) + query(node * 2 + 1, middle + 1, r, x, y);
}

void find_boss(int idx) {
    s[idx] = ++cnt;
    for (auto i : v[idx]) find_boss(i);
    e[idx] = cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x != -1) v[x].push_back(i);
    }
    find_boss(1);
    for (int i = 1; i <= m; i++) {
        int mode;
        cin >> mode;
        if (mode == 1) {
            int x, w;
            cin >> x >> w;
            update(1, 1, n, s[x], w);
        } else {
            int x;
            cin >> x;
            cout << query(1, 1, n, s[x], e[x]) << "\n";
        }
    }
}