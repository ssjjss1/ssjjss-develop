#include<iostream>
using namespace std;
int n;
int d[24][24],visited[24][24];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> d[i][j];
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j || j == k || i == k) continue;
				if (d[i][j] > d[i][k] + d[k][j]) {
					cout << -1;
					return 0;
				}
				if (d[i][j] == d[i][k] + d[k][j]) visited[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (!visited[i][j]) {
				ans += d[i][j];
			}
		}
	}
	cout << ans;
}