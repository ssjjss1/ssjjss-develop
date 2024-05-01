#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int inf = 987654321;
int n, m, k;
int a[1001];
int b[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
vector<pair<int, int>> v[1001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[x].push_back({ y,z });
	}
	for (int i = 1; i <= n; i++) {
		fill(&a[0], &a[0] + 1001, inf);
		q.push({ 0,i });
		a[i] = 0;
		while (!q.empty()) {
			int x = q.top().second, y = q.top().first;
			q.pop();
			if (a[x] != y) continue;
			for (auto j : v[x]) {
				int p = j.first, l = j.second;
				if (a[p] > a[x] + l) {
					a[p] = a[x] + l;
					q.push({ a[p],p });
				}
			}
		}
		if (i != k) b[i] += a[k];
		else for (int j = 1; j <= n; j++) b[j] += a[j];
	}
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		if (i!=k && mx <= b[i]) mx = b[i];
	}
	cout << mx;
}