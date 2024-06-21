#include<iostream>
using namespace std;
int n, m, cnt;
const int dx[] = { 0,1 }, dy[] = { 1,0 };
int visited[54][54];
char c[54][54];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited[i][j]) {
				int x = i, y = j;
				if (c[x][y] == '-') {
					while (true) {
						x += dx[0], y += dy[0];
						if (c[x][y] != '-' || visited[x][y] || y > m) break;
						visited[x][y] = 1;
					}
				}
				else if (c[x][y] == '|') {
					while (true) {
						x += dx[1], y += dy[1];
						if (c[x][y] != '|' || visited[x][y] || x > n) break;
						visited[x][y] = 1;
					}
				}
				cnt += 1;
			}
		}
	}
	cout << cnt;
}