#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k;
vector<pair<ll,ll>> v[300004];
vector<vector<ll>> f(int t, int n, int k) {
    vector<vector<ll>> d(n + 1);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
    q.push({0, t});
    d[t].push_back(0);
    while (!q.empty()) {
        ll x = q.top().second, y = q.top().first;
        q.pop();
        if (d[x].size() > k) continue;
        for (auto i : v[x]) {
            ll xx = i.first, yy = i.second, cnt = y + yy;
            if (d[xx].size() < k) {
                d[xx].push_back(cnt);
                q.push({cnt, xx});
                sort(d[xx].begin(), d[xx].end());
            } 
            else if (cnt < d[xx][k-1]) {
                d[xx][k-1] = cnt;
                q.push({cnt, xx});
                sort(d[xx].begin(), d[xx].end());
            }
        }
    }
    return d;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        v[x].push_back({y, z});
    }
    vector<vector<ll>> d = f(1, n, k);
    for (int i = 1; i <= n; i++) {
        if (d[i].size() < k) cout << -1 << '\n';
        else cout << d[i][k-1] << '\n';
    }
}