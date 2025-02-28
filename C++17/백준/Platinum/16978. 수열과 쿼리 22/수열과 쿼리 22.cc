#include <bits/stdc++.h>
#define INF 1000004
using namespace std;
int n, q;
long long d[INF], t[INF * 4];

struct P { long long x, y, z, idx; };

void update(int node, int l, int r, int idx, long long val) {
    if (l > idx || r < idx) return;
    if (l == r) {
        t[node] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(node * 2, l, mid, idx, val);
    update(node * 2 + 1, mid + 1, r, idx, val);
    t[node] = t[node * 2] + t[node * 2 + 1];
}

long long query(int node, int l, int r, int x, int y) {
    if (l > y || r < x) return 0;
    if (l >= x && r <= y) return t[node];
    int mid = (l + r) / 2;
    return query(node * 2, l, mid, x, y) + query(node * 2 + 1, mid + 1, r, x, y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        update(1, 1, n, i, d[i]);
    }
    
    cin >> q;
    vector<pair<int, long long>> v1;
    vector<P> v2;
    vector<long long> ans;
    
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            long long y;
            cin >> x >> y;
            v1.push_back({x, y});
        } else {
            int x, y, z;
            cin >> x >> y >> z;
            v2.push_back({x, y, z, (long long)v2.size()});
        }
    }
    
    sort(v2.begin(), v2.end(), [&](P &a, P &b) {
        return a.x < b.x;
    });
    
    ans.resize(v2.size());
    
    int idx = 0;
    for (auto q : v2) {
        while (idx < q.x) {
            update(1, 1, n, v1[idx].first, v1[idx].second);
            idx++;
        }
        ans[q.idx] = query(1, 1, n, q.y, q.z);
    }
    
    for (long long res : ans) cout << res << '\n';
}