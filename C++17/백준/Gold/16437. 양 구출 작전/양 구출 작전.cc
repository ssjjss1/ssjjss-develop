#include<bits/stdc++.h>
using namespace std;

long long n;
vector<int> d[200001];
long long sheep[200001], wolf[200001];

long long dfs(int u) {
	long long survivedSheep = sheep[u];

	for (auto v : d[u]) {
		survivedSheep += dfs(v);
	}

	if (wolf[u]) {
		if (survivedSheep <= wolf[u]) return 0;
		else return survivedSheep - wolf[u];
	}

	return survivedSheep;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for(int i = 2; i <= n; i++) {
		char c;
		int cnt, p;
		cin >> c >> cnt >> p;

		if(c == 'S') {
			sheep[i] = cnt;
		} else {
			wolf[i] = cnt;
		}

		d[p].push_back(i);
	}

	cout << dfs(1);
}