#include <bits/stdc++.h>
#define T tuple<int,int,int> 
using namespace std;

int k, n, m;
struct P {
    int v, ti, hi;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n >> m;
    vector<P> p[n+4];
    for (int i = 0; i < m; i++) {
        int u, v, h, t;
        cin >> u >> v >> t >> h;
        p[u].push_back({v, t, h});
        p[v].push_back({u, t, h});
    }

    int A, B;
    cin >> A >> B;

    vector<vector<int>> dist(n+4, vector<int>(k+1, INT_MAX));
    priority_queue<T, vector<T>, greater<T>> pq;

    dist[A][0] = 0;
    pq.push({0, A, 0});

    while (!pq.empty()) {
        auto [cx, u, d] = pq.top();
        pq.pop();

        if (u == B) {
            cout << cx;
            return 0;
        }

        if (dist[u][d] < cx) continue;

        for (auto &nx : p[u]) {
            int v = nx.v;
            int nd = d + nx.hi;
            if (nd >= k) continue; 
            int nt = cx + nx.ti;

            if (nt < dist[v][nd]) {
                dist[v][nd] = nt;
                pq.push({nt, v, nd});
            }
        }
    }

    cout << -1;
}