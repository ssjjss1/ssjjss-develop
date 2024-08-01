#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int inf = 1e8 + 4;
int n, m, q;
int a[504];
pair<int, int> d[504][504];
vector<pair<int, int>> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		v.push_back({ a[i],i});
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = { inf,max(a[i],a[j]) };
		}
	}
	for (int i = 1, x, y, z; i <= m; i++) {
		cin >> x >> y >> z;
		d[x][y] = { z,max(a[x],a[y]) };
		d[y][x] = { z,max(a[x],a[y]) };
	}
	sort(v.begin(), v.end());
	for (auto k : v) {
		int xx = k.second;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int mx = max(d[i][xx].second, d[xx][j].second);
				if (d[i][j].first + d[i][j].second > d[i][xx].first + d[xx][j].first + mx) {
					d[i][j].first = d[i][xx].first + d[xx][j].first;
					d[i][j].second = mx;
				}
			}
		}
	}
	for (int i = 1, x, y; i <= q; i++) {
		cin >> x >> y;
		if (d[x][y].first != inf) cout << d[x][y].first + d[x][y].second << "\n";
		else cout << -1 << "\n";
	}
}