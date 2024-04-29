#include<iostream>
#include<vector>
using namespace std;
int n, m, k, t;//k:친구 수, t:하계
int x, y;
int dp[301][301];
int a[301];
vector<pair<int, int>> v;
int f(int b, int c, int p) {//p: 이전에 구간에 있던 사람 수
	if (b == v.size()) return 0;
	if (dp[b][c]) return dp[b][c];
	int& ref = dp[b][c];
	int pay = (t - v[b].second > 0 ? t - v[b].second : 0);
	int later_pay = (p >= pay ? 0 : pay - p );
	if (c - later_pay >= 0) return ref = max(f(b + 1, c - later_pay, pay) + v[b].first, f(b + 1, c, 0));
	else return ref = f(b + 1, c, 0);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k >> t;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		for (int j = x; j < y; j++) {
			int num = a[j];
			num += 1;
			a[j] = min(t, num);
		}
	}
	int ff = a[1];
	int cnt = 1;
	for (int i = 2; i <= n; i++) {
		if (ff != a[i]) {
			v.push_back({ cnt,ff });
			cnt = 0;
			ff = a[i];
		}
		cnt += 1;
	}
	v.push_back({ cnt,ff});
	cout << f(0, k, 0);
}