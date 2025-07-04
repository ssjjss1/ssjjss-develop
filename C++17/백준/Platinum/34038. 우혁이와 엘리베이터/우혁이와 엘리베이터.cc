#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, e, k;
ll T1, T2;
vector<ll> ti(504);
vector<ll> adj1[504];
vector<pair<ll, ll>> elevator[504];

struct Node {
    ll x, usedStair, ti;
    bool operator<(const Node& o) const {
        return ti > o.ti;  
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> e >> k;
    cin >> T1 >> T2;

    map<pair<ll, ll>, ll> minEdge;

    for (int i = 1; i <= m; i++) {
        ll c;
        cin >> c >> ti[i];
        adj1[i].resize(c);
        for (int j = 0; j < c; j++) {
            cin >> adj1[i][j];
        }

        sort(adj1[i].begin(), adj1[i].end());
        for (int j = 1; j < c; j++) {
            ll u = adj1[i][j - 1], v = adj1[i][j];
            ll cost = abs(v - u) * ti[i];
            pair<ll, ll> key = {u, v};
            if (minEdge.count(key)) {
                minEdge[key] = min(minEdge[key], cost);
            } else {
                minEdge[key] = cost;
            }
        }
    }

    for (auto [p, cost] : minEdge) {
        ll u = p.first, v = p.second;
        elevator[u].emplace_back(v, cost);
        elevator[v].emplace_back(u, cost); 
    }

    const ll INF = 1e18;
    vector<vector<ll>> visited(n + 4, vector<ll>(k + 4, INF));
    priority_queue<Node> pq;

    visited[1][0] = 0;
    pq.push({1, 0, 0});

    while (!pq.empty()) {
        auto [cFloor, usedStair, cTime] = pq.top();
        pq.pop();

        if (cFloor == e) {
            cout << cTime;
            return 0;
        }

        if (visited[cFloor][usedStair] < cTime) continue;

        if (cFloor < n && usedStair + 1 <= k) {
            ll cost = T1 + usedStair * T2;
            if (visited[cFloor + 1][usedStair + 1] > cTime + cost) {
                visited[cFloor + 1][usedStair + 1] = cTime + cost;
                pq.push({cFloor + 1, usedStair + 1, cTime + cost});
            }
        }

        if (cFloor > 1 && usedStair + 1 <= k) {
            ll cost = T1 + usedStair * T2;
            if (visited[cFloor - 1][usedStair + 1] > cTime + cost) {
                visited[cFloor - 1][usedStair + 1] = cTime + cost;
                pq.push({cFloor - 1, usedStair + 1, cTime + cost});
            }
        }

        for (auto [nFloor, cost] : elevator[cFloor]) {
            if (visited[nFloor][usedStair] > cTime + cost) {
                visited[nFloor][usedStair] = cTime + cost;
                pq.push({nFloor, usedStair, cTime + cost});
            }
        }
    }

    cout << -1;
}