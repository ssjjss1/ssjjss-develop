#include <bits/stdc++.h>
using namespace std;

vector<int> adj[2004];
int n, m, q;
const int INF = 1e9;

vector<int> bfs(int x, vector<int> g[]) {
    vector<int> d(n + 1, INF);
    queue<int> q;
    d[x] = 0;
    q.push(x);

    while (!q.empty()) {
        int cx = q.front(); q.pop();
        for (auto nx : g[cx]) {
            if (d[nx] == INF) {
                d[nx] = d[cx] + 1;
                q.push(nx);
            }
        }
    }

    return d;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }

    while (q--) {
        int u, v;
        cin >> u >> v;

        vector<int> graphU = bfs(u, adj);
        vector<int> graphV = bfs(v, adj);

        int ans = INF;
        for (int i = 1; i <= n; i++) {
            if (graphU[i] != INF && graphV[i] != INF) {
                  ans = min(ans, max(graphU[i], graphV[i]));
            }
        }

        cout << (ans == INF ? -1 : ans) << "\n";
    }
}