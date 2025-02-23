#include <bits/stdc++.h>
using namespace std;

class construction {
public:
	int n, m;
	vector<int> Rank;
	int res = 0;

	int find(int x) {
		if (Rank[x] < 0) return x;
		return Rank[x] = find(Rank[x]);
	}

	void merge(int x, int y) {
		x = find(x);
		y = find(y);

		if (x == y) return;

		if (x < y) {
			Rank[x] += Rank[y];
			Rank[y] = x;
		}
		else {
			Rank[y] += Rank[x];
			Rank[x] = y;
		}
	}

	void ans() {
		cin >> n >> m;
		Rank.assign(n + 1, -1);

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			merge(a, b);
		}

		for (int i = 1; i <= n; i++) {
			if (Rank[i] < 0) res+=1;
		}

		cout << res - 1;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	construction k;
	k.ans();
}