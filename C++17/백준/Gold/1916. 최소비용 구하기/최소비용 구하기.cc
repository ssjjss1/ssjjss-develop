#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m;
const int inf = 987654321;
int a[200001];
vector<pair<int, int>> v[2001];
priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[x].push_back({ y,z });
	}
	int x, y;
	cin >> x >> y;
	fill(a, a + 200001, inf);
	a[x] = 0;
	q.push({ 0 ,x });
	while (!q.empty()) {
		int x1 = q.top().second, y1 = q.top().first;
		q.pop();
		if (a[x1] != y1) continue;
		for (auto i : v[x1]) {
			int p = i.first, l = i.second;
			if (a[p] > a[x1] + l) {
				a[p] = a[x1] + l;
				q.push({ a[p],p });
			}
		}
	}
	cout << a[y];
}