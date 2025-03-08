#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX;

struct P {
    ll e, d;
};

ll n, k, x, y;
vector<P> v1[200004], v2[200004];
ll visited[200004];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> x >> y;

    for (int i = 1; i <= x; i++) {
        ll s, e, d;
        cin >> s >> e >> d;
        v1[s].push_back({e, d});
        v1[e].push_back({s, d});
    }

    for (int i = 1; i <= y; i++) {
        ll s, e, d;
        cin >> s >> e >> d;
        v2[s].push_back({e, d});
        v2[e].push_back({s, d});
    }

    fill(visited, visited + n + 1, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    
    visited[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        ll d = pq.top().first, e = pq.top().second;
        pq.pop();

        if (d > visited[e]) continue;
        if (e == n) {
            cout << d;
            return 0;
        }

        for (auto i : v1[e]) {
            ll v = i.e, t = i.d;
            if (d + t < visited[v]) {
                visited[v] = d + t;
                pq.push({visited[v], v});
            }
        }

        for (auto i : v2[e]) {
            ll v = i.e, t = i.d;
            ll a_t = max(d, k) + t;
            if (a_t < visited[v]) {
                visited[v] = a_t;
                pq.push({visited[v], v});
            }
        }
    }
}