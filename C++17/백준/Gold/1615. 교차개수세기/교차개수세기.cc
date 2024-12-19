#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> t;
vector<pair<int, int>> v;
void update(int node, int l, int r, int idx) {
    if (l == r) {
        t[node] += 1;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) update(node * 2, l, mid, idx);
    else update(node * 2 + 1, mid + 1, r, idx);
    t[node] = t[node * 2] + t[node * 2 + 1];
}
int query(int node, int l, int r, int x, int y) {
    if (x > r || y < l) return 0;
    if (x <= l && r <= y) return t[node];
    int mid = (l + r) / 2;
    return query(node * 2, l, mid, x, y) + query(node * 2 + 1, mid + 1, r, x, y);
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    t.resize(4 * n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    long long cnt = 0;
    for (auto [x, y] : v) {
        cnt += query(1, 1, n, y + 1, n);
        update(1, 1, n, y);
    }
    cout << cnt;
}