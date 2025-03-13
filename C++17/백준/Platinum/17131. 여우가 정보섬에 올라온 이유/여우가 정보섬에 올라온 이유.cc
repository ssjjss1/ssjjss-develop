#include<bits/stdc++.h>
#define MOD 1000000007
#define INF 200004
using namespace std;
long long n;

long long t[INF * 8]; 
vector<pair<long long, long long>> v;

void update(int node, int l, int r, int idx) {
	if (idx < l || idx > r) return;
	if (l == r) {
		t[node] += 1;
		return;
	}
	int middle = (l + r) / 2;
	update(node * 2, l, middle, idx);
	update(node * 2 + 1, middle + 1, r, idx);
	t[node] = t[node * 2] + t[node * 2 + 1];
}

long long query(int node, int l, int r, int x, int y) {
	if (y < l || x > r) return 0;
	if (x <= l && r <= y) return t[node];
	int middle = (l + r) / 2;
	return (query(node * 2, l, middle, x, y) + query(node * 2 + 1, middle + 1, r, x, y)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[i] = {y + INF, x + INF};
	}

	sort(v.begin(), v.end(), [](const pair<long long, long long>& a, const pair<long long, long long>& b) {
		if (a.first == b.first) return a.second < b.second;
		return a.first > b.first;
	});

	long long res = 0;
	int i = 0;
	while (i < n){
		int j = i;
		while (j < n && v[i].first == v[j].first) j++;

		for (int k = i; k < j; k++) {
			int x = v[k].second;
			long long l = query(1, 0, 2 * INF - 1, 0, x - 1);
			long long r = query(1, 0, 2 * INF - 1, x + 1, 2 * INF - 1);
			res = (res + (l * r) % MOD) % MOD;
		}

		for (int k = i; k < j; k++) {
			update(1, 0, 2 * INF - 1, v[k].second);
		}

		i = j;
	}

	cout << res;
}