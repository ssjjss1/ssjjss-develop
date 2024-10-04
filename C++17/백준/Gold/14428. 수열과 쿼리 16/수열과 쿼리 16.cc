#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf = 1e5;
ll d[inf + 4], t[4 * inf + 4];
int n, k;
void init(int node, int l, int r) {
    if (l == r) {
        t[node] = l;
        return;
    }
    int m = (l + r) / 2;
    init(node * 2, l, m);
    init(node * 2 + 1, m + 1, r);
    t[node] = (d[t[node * 2]] <= d[t[node * 2 + 1]] ? t[node * 2] : t[node * 2 + 1]);
}
void update(int x, int v, int node, int l, int r) {
    if (l == r) {
        t[node] = l;
        d[l] = v;
        return;
    }
    int m = (l + r) / 2;
    if (x <= m) update(x, v, node * 2, l, m);
    else update(x, v, node * 2 + 1, m + 1, r);
    t[node] = (d[t[node * 2]] <= d[t[node * 2 + 1]] ? t[node * 2] : t[node * 2 + 1]);
}
int query(int x, int y, int node, int l, int r) {
    if (y < l || r < x) return -1;
    if (x <= l && r <= y) return t[node];
    int m = (l + r) / 2;
    int l1 = query(x, y, node * 2, l, m), r1 = query(x, y, node * 2 + 1, m + 1, r);
    if (l1 == -1) return r1;
    if (r1 == -1) return l1;
    return (d[l1] <= d[r1] ? l1 : r1);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> d[i];
    init(1, 1, n);
    cin >> k;
    while (k--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 1) update(y, z, 1, 1, n);
        else if (x == 2) cout << query(y, z, 1, 1, n) << "\n";
    }
}