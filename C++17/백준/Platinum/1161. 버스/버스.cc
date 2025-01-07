#include<bits/stdc++.h>
#define INF 50000
using namespace std;

typedef long long ll;

int k, n, c;
ll t[INF * 4], lazy[INF * 4];

void propagate(int node, int l, int r) {
	if (lazy[node] != 0) {
		t[node] += lazy[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int l, int r, int x, int y, int val) {
	propagate(node, l, r);
	if (y < l || r < x) return;
	if (x <= l && r <= y) {
		lazy[node] += val;
		propagate(node, l, r);
		return;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, x, y, val);
	update(node * 2 + 1, mid + 1, r, x, y, val);
	t[node] = max(t[node * 2], t[node * 2 + 1]);
}

ll query(int node, int l, int r, int x, int y) {
	propagate(node, l, r);
	if (y < l || r < x) return 0;
	if (x <= l && r <= y) return t[node];
	int mid = (l + r) / 2;
	return max(query(node * 2, l, mid, x, y), query(node * 2 + 1, mid + 1, r, x, y));
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> k >> n >> c;
	vector<tuple<ll, ll, ll>> v(k+4);

	for (int i = 0; i < k; i++) {
		int s, e, m; cin >> s >> e >> m;
		v[i] = {s, e, m};
	}

	sort(v.begin(), v.end(), [](tuple<ll, ll, ll> &a, tuple<ll, ll, ll> &b) {
		return get<1>(a) < get<1>(b);
	});

	ll ans = 0;
	for (auto [s, e, m] : v) {
		ll cu_max = query(1, 1, n, s, e - 1);
		ll avail = min(m, c - cu_max);
		if (avail > 0) {
			ans += avail;
			update(1, 1, n, s, e - 1, avail);
		}
	}
	cout << ans;
}