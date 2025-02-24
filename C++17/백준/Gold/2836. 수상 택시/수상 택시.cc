#include<bits/stdc++.h>
using namespace std;

long long n, m;

struct Pair {
	long long x, y;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	vector<Pair> v;
	for (int i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		if (x < y) continue;
		v.push_back({y, x});
	}

	if (v.empty()) {
		cout << m;
		return 0;
	}

	sort(v.begin(), v.end(), [](Pair a, Pair b) {
		return a.x < b.x;
	});

	long long cur_l = v[0].x, cur_r = v[0].y, ans = m;
	for (int i = 1; i < v.size(); i++) {
		if (cur_r >= v[i].x) {
			cur_r = max(cur_r, v[i].y);
		} else {
			ans += 2 * (cur_r - cur_l);
			cur_l = v[i].x;
			cur_r = v[i].y;
		}
	}
	ans += 2 * (cur_r - cur_l);
	cout << ans;
}