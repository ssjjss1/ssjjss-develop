#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n, m, k;
int a[1001][1001];
bool dp[1001][1001][11];
const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
struct p {
	int b, c, d, e, f;
};
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			a[i][j] = c - '0';
		}
	}
	if (n == 1 && m == 1) {
		cout << 1;
		return 0;
	}
	queue<p> q;
	dp[1][1][0] = 1;
	q.push({ 1,1,0,0,1 });
	while (!q.empty()) {
		int x = q.front().b, y = q.front().c, cnt = q.front().d, day = q.front().e, step = q.front().f;
		q.pop();
		if (x == n && y == m) {
			cout << step;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (xx > 0 && yy > 0 && xx <= n && yy <= m) {
				if (day == 0) {
					if (!a[xx][yy] && !dp[xx][yy][cnt]) {
						dp[xx][yy][cnt] = 1;
						q.push({ xx,yy,cnt,1,step + 1 });
					}
					else if (a[xx][yy] && !dp[xx][yy][cnt + 1] && cnt < k) {
						dp[xx][yy][cnt + 1] = 1;
						q.push({ xx,yy,cnt + 1,1,step + 1 });
					}
				}
				else {
					if (!a[xx][yy] && !dp[xx][yy][cnt]) {
						dp[xx][yy][cnt] = 1;
						q.push({ xx,yy,cnt,0,step + 1 });
					}
					else q.push({ x,y,cnt,0,step + 1 });
				}
			}
		}
	}
	cout << -1;
}