#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	vector<int> v(n, 0), d(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	while (true) {
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (v[i] != 1) {
				flag = false;
				break;
			}
		}
		if (flag) {
			int sum = 0;
			for (int i = 0; i < n; i++) {
				sum += d[i] * d[i];
			}
			cout << sum;
			return 0;
		}

		int r = -1;
		for (int i = 0; i < n; i++) {
			if (v[i] == 0) r = i;
		}

		int l = r, distance = 0;
		while (true) {
			if (v[l] != 0) break;
			if (l == 0) l = n;
			l -= 1;
			distance += 1;
		}

		v[l] -= 1;
		v[r] += 1;
		d[r] += distance + d[l];
		d[l] = 0;
	}
}