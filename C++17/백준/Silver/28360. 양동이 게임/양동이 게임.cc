#include<iostream>
#include<vector>
#include<queue>
#include<iomanip>
#include<algorithm>
using namespace std;
int n, m;
int a[101];
double d[101];
vector<int> v[101];
queue<int> q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	d[1] = 100.0;
	for (int i = 1, x, y; i <= m; i++) cin >> x >> y, v[x].push_back(y), a[y] += 1;
	for (int i = 1; i <= n; i++) {
		if (!a[i]) q.push(i);
	}
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (auto i : v[x]) {
			d[i] += d[x] / v[x].size();
			if (!--a[i]) q.push(i);
		}
		if (!v[x].empty()) d[x] = 0;
	}
	cout << fixed << setprecision(20) << *max_element(d + 1, d + n + 1);
}