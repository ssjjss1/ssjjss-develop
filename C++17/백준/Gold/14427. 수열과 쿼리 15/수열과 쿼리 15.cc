#include<iostream>
using namespace std;
int n, q, d[200004], t[200004];
void init(int node, int l, int r) {
    if (l == r) {
        t[node] = d[l];
        return;
    }
    int m = (l + r) / 2;
    init(node * 2, l, m);
    init(node * 2 + 1, m + 1, r);
    t[node] = min(t[node * 2], t[node * 2 + 1]);
}
void update(int x, int v, int node, int l, int r) {
    if (l == r) {
        t[node] = v;
        return;
    }
    int m = (l + r) / 2;
    if (x <= m) update(x, v, node * 2, l, m);
    else update(x, v, node * 2 + 1, m + 1, r);
    t[node] = min(t[node * 2], t[node * 2 + 1]);
}
int query(int node, int l, int r) {
    if (l == r) return l;
    int m = (l + r) / 2;
    if (t[node] == t[node * 2]) return query(node * 2, l, m);
    else return query(node * 2 + 1, m + 1, r);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> d[i];
    init(1, 1, n);
    cin >> q;
    while (q--) {
        int x, y, z;
        cin >> x;
        if (x == 1) {
            cin >> y >> z;
            update(y, z, 1, 1, n);
        } else {
            cout << query(1, 1, n) << "\n";
        }
    }
}