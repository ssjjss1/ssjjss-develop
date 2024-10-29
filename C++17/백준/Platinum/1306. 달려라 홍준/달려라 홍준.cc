#include<iostream>
using namespace std;
typedef long long ll;
const int INF = 1000000;
ll n, m, d[INF+4], t[INF*4+4];
void init(int node, int l, int r) {
    if (l == r) { t[node] = d[l]; return; }
    int middle = (l + r) / 2;
    init(node * 2, l, middle);
    init(node * 2 + 1, middle + 1, r);
    t[node] = max(t[node * 2], t[node * 2 + 1]);
}
ll query(int node, int l, int r, int x, int y) {
    if (y < l || r < x) return 0; 
    if (x <= l && r <= y) return t[node];
    int middle = (l + r) / 2;
    return max(query(node * 2, l, middle, x, y), query(node * 2 + 1, middle + 1, r, x, y));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    init(1, 1, n); 
    for (int i = m; i <= n - m + 1; i++) {
        cout << query(1, 1, n, i - m + 1, i + m - 1) << " ";
    }
}