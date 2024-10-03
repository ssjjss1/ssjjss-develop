#include<iostream>
using namespace std;
typedef long long ll;
const int inf = 1000000;
ll t[4 * inf + 4];
int n;
void update(int node, int l, int r, int x, ll diff) {
    if (x < l || x > r) return;
    t[node] += diff;
    if (l != r) {
        int m = (l + r) / 2;
        update(node * 2, l, m, x, diff);
        update(node * 2 + 1, m + 1, r, x, diff);
    }
}
ll query(int node, int l, int r, int k) {
    if (l == r) return l;
    int m = (l + r) / 2;
    if (t[node * 2] >= k) return query(node * 2, l, m, k);
    else return query(node * 2 + 1, m + 1, r, k - t[node * 2]);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    while (n--) {
        ll a, b, c;
        cin >> a;
        if (a == 1) {
            cin >> b;
            ll k = query(1, 1, inf, b);
            cout << k << '\n';
            update(1, 1, inf, k, -1);
        }
        else {
            cin >> b >> c;
            update(1, 1, inf, b, c);
        }
    }
}