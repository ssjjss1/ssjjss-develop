#include <bits/stdc++.h>
#define INF 100004
using namespace std;

int n, m, cnt;
long long t[INF * 4], lazy[INF * 4];
int s[INF], e[INF];
vector<int> v[INF];

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

void update(int node, int l, int r, int x, int y, int diff) {
    propagation(node, l, r);
    if (r < x || y < l) return;
    if (x <= l && r <= y) {
        lazy[node] += diff;
        propagation(node, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(node * 2, l, mid, x, y, diff);
    update(node * 2 + 1, mid + 1, r, x, y, diff);
    t[node] = t[node * 2] + t[node * 2 + 1];
}

long long query(int node, int l, int r, int x) {
    propagation(node, l, r);
    if (l == r) return t[node];
    int mid = (l + r) / 2;
    if (x <= mid) return query(node * 2, l, mid, x);
    else return query(node * 2 + 1, mid + 1, r, x);
}

void boss(int idx) {
    s[idx] = ++cnt;
    for (auto i : v[idx]) boss(i);
    e[idx] = cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x != -1) v[x].push_back(i);
    }

    boss(1);

    for (int i = 1; i <= m; i++) {
        int mode;
        cin >> mode;
        if (mode == 1) {
            int x, w;
            cin >> x >> w;
            update(1, 1, n, s[x], e[x], w);
        } else {
            int x;
            cin >> x;
            cout << query(1, 1, n, s[x]) << "\n";
        }
    }
}