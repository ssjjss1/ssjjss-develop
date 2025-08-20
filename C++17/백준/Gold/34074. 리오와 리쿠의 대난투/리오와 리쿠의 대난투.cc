#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	if (n == 1 && m == 1) {
		cout << -1;
		return 0;
	}
	
	if(n==1&&m==2) {
		cout<<3<<"\n"<<"1 4";
		return 0;
	}
	
	vector<int> a, b;
	int cx = 1;

	if (n >= m) {
		for (int i = 0; i < n - 1; i++) {
			a.push_back(cx++);
		}
		if (cx == INF) cx--;
		a.push_back(INF);

		while (b.size() < m) {
			if (cx == INF) cx--;
			b.push_back(cx++);
		}
	} else {
		for (int i = 0; i < m - 1; i++) {
			b.push_back(cx++);
		}
		if (cx == INF) cx--;
		b.push_back(INF);

		while (a.size() < n) {
			if (cx == INF) cx--;
			a.push_back(cx++);
		}
	}

	for (auto x : a) cout << x << " ";
	cout << "\n";
	for (auto x : b) cout << x << " ";
	cout << "\n";
}