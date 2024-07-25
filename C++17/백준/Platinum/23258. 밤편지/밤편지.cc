#include<iostream>
using namespace std;
const int inf = 987654321;
int n, m;
int d[304][304][304];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> d[i][j][0];
			if (d[i][j][0] == 0 && i != j) d[i][j][0] = inf;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j][k] = min(d[i][j][k - 1], d[i][k][k - 1] + d[k][j][k - 1]);
			}
		}
	}
	while (m--) {
		int c, s, e;
		cin >> c >> s >> e;
		if (d[s][e][c - 1] != inf) cout << d[s][e][c - 1] << "\n";
		else cout << -1 << "\n";
	}
}