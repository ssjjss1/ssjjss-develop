#include<bits/stdc++.h>
#define INF 100004
using namespace std;

vector<int> adj[INF];
vector<int> visited(INF, 0), dist(INF, -1);
int order = 1;
long long res = 0;

void dfs(int cx, int d) {
    visited[cx] = order++;
    dist[cx] = d;

    for (int nx : adj[cx]) {
        if (!visited[nx]) {
            dfs(nx, d + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(k, 0);

    for (int i = 1; i <= n; i++) {
        if (visited[i]) res += 1LL * visited[i] * dist[i];
    }

    cout << res;
}