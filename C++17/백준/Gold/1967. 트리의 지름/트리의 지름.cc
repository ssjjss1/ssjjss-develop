#include<iostream>
#include<vector>
using namespace std;
int n,mx;
vector<pair<int,int>> v[10001];
int visited[100001];
void f(int x, int k) {
	if (mx <= k) mx=k;
	for (int i = 0; i < v[x].size(); i++) {
		if (!visited[v[x][i].first]) {
			visited[x] = 1;
			f(v[x][i].first, k + v[x][i].second);
			visited[x] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1, x, y, w; i < n; i++) {
		cin >> x >> y >> w;
		v[x].push_back({ y, w });
		v[y].push_back({ x, w });
	}
	for (int i = 1; i <= n; i++) {
		fill(visited, visited + 10001, 0);
		f(i, 0);
	}
	cout << mx;
}