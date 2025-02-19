#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> v, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (long long i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			v.push_back(i);
			n /= i;
		}
	}
	if (n > 1) v.push_back(n);

	if (v.size() < 2) {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < v.size(); i += 2) {
		if (i == v.size() - 1) {
		      ans.back() *= v[i];
		} else {
		      ans.push_back(v[i] * v[i + 1]);
		}
	}

	for (auto i : ans) cout << i << " ";
}