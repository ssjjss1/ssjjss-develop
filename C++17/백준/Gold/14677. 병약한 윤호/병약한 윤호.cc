#include <bits/stdc++.h>
using namespace std;

struct P {
	int l, r, t;
};

int n;
string s;
int d[1504];
int dp[1504][1504];

void bfs() {
	queue<P> q;
	q.push({0, 3 * n - 1, 0});
	dp[0][3 * n - 1] = 0;

	while (!q.empty()) {
		int l = q.front().l, r = q.front().r, t = q.front().t;
		int cur = dp[l][r];
		q.pop();

		if (l <= r && d[l] == t) {
			if (dp[l + 1][r] < cur + 1) {
				dp[l + 1][r] = cur + 1;
				q.push({l + 1, r, (t + 1) % 3});
			}
		}

		if (l <= r && d[r] == t) {
			if (dp[l][r - 1] < cur + 1) {
				dp[l][r - 1] = cur + 1;
				q.push({l, r - 1, (t + 1) % 3});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	for (int i = 0; i < 3 * n; i++) {
		if (s[i] == 'B') d[i] = 0;
		if (s[i] == 'L') d[i] = 1;
		if (s[i] == 'D') d[i] = 2;
	}

	fill(&dp[0][0], &dp[1503][1503] + 1, -1);

	bfs();

	int mx = 0;
	for (int i = 0; i < 3 * n; i++) {
		for (int j = 0; j < 3 * n; j++) {
			mx = max(mx, dp[i][j]);
		}
	}

	cout << mx;
}