#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int n, m;
vector<ll> t;
vector<pair<ll, ll>> adj[200004];
vector<pair<ll, ll>> revAdj[200004];

struct Node {
	ll dist, cnt, u;
	bool operator<(const Node& o) const {
		if (cnt != o.cnt) return cnt > o.cnt;
		return dist > o.dist;
	}
};

struct NodeMax {
	ll dist, cnt, u;
	bool operator<(const NodeMax& o) const {
		if (cnt != o.cnt) return cnt > o.cnt;
		return dist < o.dist;
	}
};

vector<pair<ll, ll>> dijkstraMin(int s, vector<pair<ll, ll>> g[]) {
	vector<pair<ll, ll>> d(n + 1, { INF, INF });
	priority_queue<Node> pq;
	d[s] = { 0, 0 };
	pq.push({ 0, 0, s });

	while (!pq.empty()) {
		auto [cost, cnt, u] = pq.top();
		pq.pop();
		if (d[u].second < cnt || (d[u].second == cnt && d[u].first < cost)) continue;
		for (auto [v, w] : g[u]) {
			ll nc = cost + w + t[v];
			ll nt = cnt + 1;
			if (nt < d[v].second || (nt == d[v].second && nc < d[v].first)) {
				d[v] = { nc, nt };
				pq.push({ nc, nt, v });
			}
		}
	}
	return d;
}

vector<pair<ll, ll>> dijkstraMax(int s, vector<pair<ll, ll>> g[]) {
	vector<pair<ll, ll>> d(n + 1, { -INF, INF });
	priority_queue<NodeMax> pq;
	d[s] = { 0, 0 };
	pq.push({ 0, 0, s });

	while (!pq.empty()) {
		auto [cost, cnt, u] = pq.top();
		pq.pop();
		if (d[u].second < cnt || (d[u].second == cnt && d[u].first > cost)) continue;
		for (auto [v, w] : g[u]) {
			ll nc = cost + w + t[v];
			ll nt = cnt + 1;
			if (nt < d[v].second || (nt == d[v].second && nc > d[v].first)) {
				d[v] = { nc, nt };
				pq.push({ nc, nt, v });
			}
		}
	}
	return d;
}

ll dijkstra1() {
	auto to = dijkstraMin(1, adj);
	auto from = dijkstraMin(1, revAdj);
	ll res = INF;

	ll cntMin = INF;
	for (int i = 2; i <= n; i++) {
		if (to[i].first == INF || from[i].first == INF) continue;
		if (cntMin > to[i].second + from[i].second) {
			res = to[i].first + from[i].first - t[i];
			cntMin = to[i].second + from[i].second;
		} else if (cntMin == to[i].second + from[i].second) {
			res = min(res, to[i].first + from[i].first - t[i]);
		}
	}
	return res;
}

ll dijkstra2() {
	auto to = dijkstraMax(1, adj);
	auto from = dijkstraMax(1, revAdj);
	ll res = -INF;

	ll cntMin = INF;
	for (int i = 2; i <= n; i++) {
		if (to[i].first == -INF || from[i].first == -INF) continue;
		if (cntMin > to[i].second + from[i].second) {
			res = to[i].first + from[i].first - t[i];
			cntMin = to[i].second + from[i].second;
		} else if (cntMin == to[i].second + from[i].second) {
			res = max(res, to[i].first + from[i].first - t[i]);
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	t.resize(n + 1);
	t[1] = 0;
	for (int i = 2; i <= n; i++) {
		cin >> t[i];
	}

	for (int i = 0; i < m; i++) {
		ll v, w, f;
		cin >> v >> w >> f;
		adj[v].push_back({ w, f });
		revAdj[w].push_back({ v, f });
	}

	ll a = dijkstra1();
	ll b = dijkstra2();

	cout << a << '\n' << b;
}