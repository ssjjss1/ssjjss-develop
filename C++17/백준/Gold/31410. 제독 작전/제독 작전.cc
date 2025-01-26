#include <bits/stdc++.h>
using namespace std;

long long n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	vector<pair<int, long long>> a(n);
	long long l = 0, r = 0;

	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

	sort(a.begin(), a.end());

	long long mx = a[n - 1].first, mn = a[0].first;

	for (int i = 0; i < n; i++) {
		l += (a[i].first - mn) + a[i].second;
		r += (mx - a[i].first) + a[i].second;
	}

	long long ans = LLONG_MAX;

	for (int i = 0; i < n; i++) {
		if(i==0) ans=min({ans, l-(mx-mn)-a[n-1].second, l-(n-1)*(a[1].first-mn)-a[0].second});
		if (i != 0) ans = min(ans, l - (a[i].first - mn) - a[i].second);
		if (i != n - 1) ans = min(ans, r - (mx - a[i].first) - a[i].second);
		if(i==n-1) ans=min({ans, r-(mx-mn)-a[0].first, r-(n-1)*(mx-a[n-2].first)-a[n-1].second});
	}

	cout << ans;
}