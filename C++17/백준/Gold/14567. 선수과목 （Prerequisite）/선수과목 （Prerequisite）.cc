#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m;
int a[1001],d[1001];
vector<int> v[500001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1, x, y; i <= m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		a[y] += 1;
	}
	queue<pair<int,int>> q;
	for (int i = 1; i <= n; i++) {
		if (!a[i]) q.push({ i, 1 });
	}
	while (!q.empty()) {
		int x = q.front().first,y=q.front().second;
		q.pop();
		d[x] = y;
		y += 1;
		for (auto i : v[x]) {
			if (!--a[i]) q.push({ i,y });
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << d[i] << " ";
	}
}