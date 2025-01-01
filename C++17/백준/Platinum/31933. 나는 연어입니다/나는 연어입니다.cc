#include<bits/stdc++.h>
using namespace std;
int n, m, k;
vector<tuple<int, int, int>> v[5004];
vector<int> bounds;
map<int, int> ma;
set<int> points;

bool bfs(int size) {
    queue<int> q;
    vector<int> visited(n + 1, 0);
    q.push(1);
    visited[1] = 1;
    while (!q.empty()) {
        int cx = q.front();
        q.pop();

        if (cx == n) return true;
        for (auto i : v[cx]) {
            auto [nx, mn, mx] = i;
            if (mn <= size && mx >= size && !visited[nx]) {
                q.push(nx);
                visited[nx] = 1;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, w, l, r;
        cin >> u >> w >> l >> r;
        v[u].push_back({w, l, r});
        v[w].push_back({u, l, r});
        points.insert(l);
        points.insert(r + 1);
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        ma[x] += 1;
    }

    bounds.assign(points.begin(), points.end());
    int ans = 0;

    for (int i = 0; i < bounds.size() - 1; i++) {
        int l = bounds[i], r = bounds[i + 1] - 1;
        if (bfs(l)&&bfs(r)) {
            auto it1 = ma.lower_bound(l), it2 = ma.upper_bound(r);
            for (auto it = it1; it != it2; it++) {
                ans += it->second;
            }
        }
    }

    cout << ans;
}
