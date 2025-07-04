#include<bits/stdc++.h>
using namespace std;

int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool isLeap(int y) {
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int toMinutes(string ymd, string hm) {
	int year = stoi(ymd.substr(0, 4));
	int month = stoi(ymd.substr(5, 2));
	int day = stoi(ymd.substr(8, 2));

	int hour = stoi(hm.substr(0, 2));
	int minute = stoi(hm.substr(3, 2));

	int res = 0;
	for (int y = 2013; y < year; y++) {
		res += 365 * 24 * 60;
		if (isLeap(y)) res += 24 * 60;
	}

	for (int m = 1; m < month; m++) {
		res += days[m] * 24 * 60;
		if (m == 2 && isLeap(year)) res += 24 * 60;
	}

	res += (day - 1) * 24 * 60;
	res += hour * 60 + minute;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int b, c;
		cin >> b >> c;

		vector<pair<int, int>> d(b);
		for (int i = 0; i < b; i++) {
			string code, sm, st, em, et;
			cin >> code >> sm >> st >> em >> et;
			int s = toMinutes(sm, st);
			int e = toMinutes(em, et) + c;
			d[i] = {s, e};
		}

		sort(d.begin(), d.end());

		priority_queue<int, vector<int>, greater<int>> pq;
		for (auto [s, e] : d) {
			if (!pq.empty() && pq.top() <= s) pq.pop();
			pq.push(e);
		}

		cout << pq.size() << '\n';
	}
}