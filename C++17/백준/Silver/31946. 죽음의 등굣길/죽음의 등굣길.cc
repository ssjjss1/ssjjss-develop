#include<iostream>
#include<queue>
using namespace std;
int a[101][101];
int n, m, k;
int visited[101][101];
void f() {
	queue<pair<int, int>> q;
	visited[1][1] = 1;
	q.push({ 1, 1 });
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = -k; i <= k; i++) {
			for (int j = -k + abs(i); j <= k - abs(i); j++) {
				if (abs(i) + abs(j) <= k) {
					int xx = x + i, yy = y + j;
					if (xx == n && yy == m) {
						cout << "ALIVE";
						return;
					}
					if (xx<1 || yy<1 || xx>n || yy>m || visited[xx][yy] || a[xx][yy] != a[1][1]) continue;
					visited[xx][yy] = 1;
					q.push({ xx,yy });
				}
			}
		}
	}
	cout << "DEAD";
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	cin >> k;
	if (a[n][m] != a[1][1]) {
		cout << "DEAD" << "\n";
		return 0;
	}
	f();
}