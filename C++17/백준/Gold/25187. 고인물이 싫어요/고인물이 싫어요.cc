#include <bits/stdc++.h>
using namespace std;

int n, m, q;

int parent[1000004], water[1000004];

void Init() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void unionSet(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		parent[y] = x;
	}
}

int p[100004], b[100004];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> q;

	for (int i = 1; i <= n; i++) {
		cin >> water[i];
		parent[i] = i;
		p[i] = (water[i] == 1);
		b[i] = (water[i] == 0);
	}
	
	Init();
	
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		unionSet(u, v);
	}
	
	for (int i = 1; i <= n; i++) {
		int root = find(i);
		if (root != i) {
			p[root] += p[i];
			b[root] += b[i];
		}
	}

	while (q--) {
		int x;
		cin >> x;
		int root = find(x);
		if (p[root] > b[root]) cout << "1\n";
		else cout << "0\n";
	}
}