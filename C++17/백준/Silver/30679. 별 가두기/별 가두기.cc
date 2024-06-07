#include<iostream>
#include<map>
#include<vector>
using namespace std;
int n, m;
map<int, int> ma;
int a[101][101];
int dirx[] = { -1,0,1,0 },diry[] = { 0,1,0,-1 };
void f(int x, int y, int d) {
	int count = 1e5;
	int p = x;
	while(count--) {
		if (x<1 || y<1 || x>n || y>m) return;
		x += dirx[d] * a[x][y], y += diry[d] * a[x][y];
		d = (d + 1) % 4;
	}
	ma[p] = 1;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) f(i, 1, 1);
	int cnt = 0;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		if (ma[i]) cnt += ma[i], v.push_back(i);
	}
	cout << cnt<<"\n";
	for (auto i : v) {
		cout << i << " ";
	}
}