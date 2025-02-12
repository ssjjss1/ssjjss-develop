#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int T;

vector<int> dijkstra(int s, vector<pair<int, int>> v[2004]) {
    vector<int> visited(2004, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, s });
    visited[s] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first,  x = pq.top().second;
        pq.pop();

        if (visited[x] < cost) continue;

        for (auto i : v[x]) {
            int nx = i.first, n_cost = i.second;
            if (n_cost + visited[x] < visited[nx]) {
                visited[nx] = n_cost + visited[x];
                pq.push({ visited[nx], nx });
            }
        }
    }
    return visited;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    while (T--) {
        int n, m, t, s, g, h;
        vector<pair<int, int>> v[2004];
        cin >> n >> m >> t >> s >> g >> h;

        for (int i = 1; i <= m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            v[a].push_back({ b, d });
            v[b].push_back({ a, d });
        }

        vector<int> target;
        for (int i = 0; i < t; i++) {
            int x;
            cin >> x;
            target.push_back(x);
        }

        vector<int> sp = dijkstra(s, v);
        vector<int> sp_g = dijkstra(g, v);
        vector<int> sp_h = dijkstra(h, v);

        int dist = 0;
        for (auto i : v[g]) {
            if (i.first == h) {
                dist = i.second;
                break;
            }
        }

        vector<int> res;
        for (auto i : target) {
            if (sp[i] == sp[g] + dist + sp_h[i] ||
                sp[i] == sp[h] + dist + sp_g[i]) {
                res.push_back(i);
            }
        }

        sort(res.begin(), res.end());
        for (auto i : res) cout << i << " ";
        cout << "\n";
    }
}