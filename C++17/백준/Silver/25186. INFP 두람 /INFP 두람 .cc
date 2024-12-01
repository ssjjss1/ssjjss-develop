#include <bits/stdc++.h>
using namespace std;
long long mx, sum;
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		long long x; cin >> x;
		mx = max(mx, x);
		sum += x;
	}
	if(n==1&&sum==1) cout<<"Happy";
	else if (mx <= sum / 2) cout << "Happy";
	else cout << "Unhappy";
}