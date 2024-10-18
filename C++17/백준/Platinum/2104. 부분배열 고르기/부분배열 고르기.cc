#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6;
int n;
long long d[inf + 4], t1[inf * 4 + 4], t2[inf * 4 + 4], idx_t[inf * 4 + 4];
void update(int node, int l, int r) {
    if (l == r) {
        t1[node] = t2[node] = d[l];
        idx_t[node] = l; 
        return;
    }
    int m = (l + r) / 2;
    update(node * 2, l, m), update(node * 2 + 1, m + 1, r);
    if (t1[node * 2] < t1[node * 2 + 1]) {
        t1[node] = t1[node * 2];
        idx_t[node] = idx_t[node * 2];
    } 
    else {
        t1[node] = t1[node * 2 + 1];
        idx_t[node] = idx_t[node * 2 + 1];
    }
    t2[node] = t2[node * 2] + t2[node * 2 + 1];
}
tuple<long long, int, long long> query(int node, int l, int r, int x, int y) {
    if (y < l || x > r) return { LLONG_MAX, -1, 0 };  
    if (x <= l && r <= y) return { t1[node], idx_t[node], t2[node] };  
    int m = (l + r) / 2;
    auto [lf_mn, lf_idx, lf_sum] = query(node * 2, l, m, x, y);
    auto [rg_mn, rg_idx, rg_sum] = query(node * 2 + 1, m + 1, r, x, y);
    if (lf_mn < rg_mn) return { lf_mn, lf_idx, lf_sum + rg_sum };
    else return { rg_mn, rg_idx, lf_sum + rg_sum };
}
long long mx_ans(int l, int r) {
    if (l > r) return 0;
    auto [mn, idx, sum] = query(1, 1, n, l, r); 
    long long ls = mx_ans(l, idx - 1), rs = mx_ans(idx + 1, r), cs = mn * sum;
    return max({ ls, rs, cs });
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> d[i];
    update(1, 1, n);
    cout << mx_ans(1, n);
}