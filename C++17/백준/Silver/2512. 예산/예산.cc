#include<iostream>
using namespace std;
typedef long long int ll;
ll n, m, aks;
int a[10001],mx=0;
ll sum = 0;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		mx = max(mx, a[i]);
	}
	cin >> m;
	if (sum <= m) cout << mx;
	else {
		ll r = 0, l = 1e18;
		while (r <= l) {
			ll middle = (r + l) / 2, ans = 0;
			for (int i = 1; i <= n; i++) {
				ans += (middle < a[i] ? middle : a[i]);
			}
			if (ans > m) l = middle - 1;
			else r = middle + 1, aks = middle;
		}
		cout << aks;
	}
}