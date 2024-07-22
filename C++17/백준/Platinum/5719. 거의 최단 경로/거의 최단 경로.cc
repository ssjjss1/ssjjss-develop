#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18 + 4;
int n, m, a, b;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) return 0;

        vector<pair<int, int>> v1[504];
        vector<pair<int, int>> v2[504];
        cin >> a >> b;
        for (int i = 0, x, y, z; i < m; i++) {
            cin >> x >> y >> z;
            v1[x].push_back({y, z});
            v2[y].push_back({x, z});
        }

        // Dijkstra1
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        vector<ll> dist(n, inf);
        dist[a] = 0;
        pq.push({0, a});
        while (!pq.empty()) {
            ll d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (dist[u] < d) continue;
            for (auto &edge : v1[u]) {
                int v = edge.first;
                ll w = edge.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        if (dist[b] == inf) {
            cout << -1 << "\n";
            continue;
        }

        // BFS to find shortest path edges
        bool dp[504][504];
        memset(dp, 0, sizeof(dp));
        queue<int> q;
        q.push(b);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto &edge : v2[u]) {
                int v = edge.first;
                ll w = edge.second;
                if (dist[v] + w == dist[u]) {
                    if (!dp[v][u]) {
                        dp[v][u] = true;
                        q.push(v);
                    }
                }
            }
        }

        // Dijkstra2 to find the almost shortest path
        fill(dist.begin(), dist.end(), inf);
        dist[a] = 0;
        pq.push({0, a});
        while (!pq.empty()) {
            ll d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (dist[u] < d) continue;
            for (auto &edge : v1[u]) {
                int v = edge.first;
                ll w = edge.second;
                if (dist[v] > dist[u] + w && !dp[u][v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        if (dist[b] == inf) cout << -1 << "\n";
        else cout << dist[b] << "\n";
    }
}
