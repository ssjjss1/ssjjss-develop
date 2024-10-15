#include <iostream>
using namespace std;
long long n, m, ans;
long long d[10004], a[10004];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0, x; i < n; i++) cin >> x, d[x]+=1;
	for (int i = 0, x; i < n; i++) cin >> x, a[x]+=1;
	ans = n * n;
	for (int i = 1; i <= m; i++) ans -= d[i] * a[i];
	cout << ans;
}