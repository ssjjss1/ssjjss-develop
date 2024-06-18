#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
int t, n, m;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> m >> n;
		vector<vector<char>> v(n + 4, vector<char>(m + 4));
		vector<vector<int>> visited(n + 4, vector<int>(m + 4));
		vector<pair<int, int>> _v;
		int _x = 0, _y = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> v[i][j];
				visited[i][j] = 1e9;
				if (v[i][j] == '*') _v.push_back({ i,j }), visited[i][j] = 0;
				if (v[i][j] == '@') _x = i, _y = j;
			}
		}
		queue<pair<int, int>> q;
		for (auto i : _v) {
			q.push({ i.first,i.second });
		}
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i], yy = y + dy[i];
				if (v[xx][yy] == '#' || v[xx][yy] == '*' || xx<1 || yy<1 || xx>n || yy>m || visited[xx][yy] <= visited[x][y] + 1)continue;
				visited[xx][yy] = visited[x][y] + 1;
				q.push({ xx,yy });
			}
		}
		visited[_x][_y] = 0;
		q.push({ _x,_y });
		bool flag = true;
		while (!q.empty()&&flag) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i], yy = y + dy[i];
				if (xx<1 || yy<1 || xx>n || yy>m) {
					cout << visited[x][y] + 1 << "\n";
					flag = false;
					break;
				}
				if (visited[xx][yy] <= visited[x][y] + 1 || v[xx][yy] == '#') continue;
				visited[xx][yy] = visited[x][y] + 1;
				q.push({ xx,yy });
			}
		}
		if (flag) cout << "IMPOSSIBLE" << "\n";
	}
}