#include<iostream>
using namespace std;
typedef long long ll;
const int inf = 500000;
int n;
int d1[inf + 4], d2[inf + 4];
ll t[inf * 4 + 4];
void update(int node, int l, int r, int x) {
    if (x < l || x > r) return;
    if (l == r) {
        t[node] = 1;
        return;
    }
    int m = (l + r) / 2;
    update(node * 2, l, m, x);
    update(node * 2 + 1, m + 1, r, x);
    t[node] = t[node * 2] + t[node * 2 + 1];
}
ll query(int node, int l, int r, int x, int y) {
    if (y < l || x > r) return 0;
    if (x <= l && r <= y) return t[node];
    int m = (l + r) / 2;
    return query(node * 2, l, m, x, y) + query(node * 2 + 1, m + 1, r, x, y);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> d1[i];
    for (int i = 1; i <= n; i++) cin >> d2[i];
    int p[2*inf + 4];
    for (int i = 1; i <= n; i++) p[d2[i]] = i;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += query(1, 1, n, p[d1[i]] + 1, n);
        update(1, 1, n, p[d1[i]]);
    }
    cout << ans;
}