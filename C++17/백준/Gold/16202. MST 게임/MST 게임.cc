#include<bits/stdc++.h>
using namespace std;

struct P {
	int c, u, v;
};

bool compare(P a, P b) {
	return a.c < b.c;
}

vector<int> parent(20004);

void Init(int n) {
	for(int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

int n, m, k;
vector<P> adj;

bool unionSet(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	else {
		parent[b] = a;
		return true;
	}
}

int kruskal() {
	Init(n);
	int cnt = 0, sum = 0;
	for (P i : adj) {
		if (unionSet(i.u, i.v)) {
			sum += i.c;
			cnt+=1;
			if (cnt == n - 1) return sum;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj.push_back({i, u, v});
	}

	sort(adj.begin(), adj.end(), compare);

	vector<int> res;
	for (int i = 0; i < k; i++) {
		int mn = kruskal();
		res.push_back(mn);
		adj.erase(adj.begin());
	}

	for (auto i : res) cout << i << " ";
}