#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
const int inf = 1e9 + 4;
struct P {int a, b, c;};
int n, m;
int d[204][204];
vector<P> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	fill(&d[0][0], &d[0][0] + 204 * 204, inf);
	for (int i = 1; i <= n; i++) d[i][i] = 0;
	for (int i = 1,x,y,z; i <= m; i++) {
		cin >> x >> y >> z;
		v.push_back({ x,y,z });
		d[x][y] = min(d[x][y], z);
		d[y][x] = min(d[x][y], z);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int mn = inf;
	for (int i = 1; i <= n; i++) {
		int mx = 0;
		for (auto j : v) {
			mx = max(mx, d[i][j.a] + d[i][j.b] + j.c);
		}
		mn = min(mx, mn);
	}
	cout << fixed << setprecision(1) << float(mn) / 2.0;
}