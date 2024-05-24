#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m, k;
vector<int> v[100001];
int dp[100001];
int visited[100001];
int f(int x) {
	if (dp[x]) return dp[x];
	visited[x] = 1;
	int ref = 1;
	for (int i = 0, cnt; i < v[x].size(); i++) {
		cnt = v[x][i];
		if (!visited[cnt])ref += f(cnt);
	}
	dp[x] = ref;
	return ref;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1, x, y; i <= n-1; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dp[m]=f(m);
	while (k--) {
		int x;
		cin >> x;
		cout << dp[x]<<"\n";
	}
}