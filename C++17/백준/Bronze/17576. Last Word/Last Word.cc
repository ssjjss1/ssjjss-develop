#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int n;

	cin >> s >> n;

	int ans = 0;
	int len = s.length();

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		ans += x;
		len = y;
	}

	cout << s.substr(ans, len);
}