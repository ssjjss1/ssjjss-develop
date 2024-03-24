#include<iostream>
using namespace std;
typedef long long int ll;
ll n, m;
ll a[100], b[100];
ll f(int cnt,  ll y) {
	if (cnt == 0) {
		if (y == 1) return 1;
		else if (y == 0) return 0;
	}
	else if (y == 1) return 0;
	else if (y <= a[cnt - 1] + 1) return f(cnt - 1, y - 1);
	else if (y == 1 + a[cnt - 1] + 1) return b[cnt - 1] + 1;
	else if (y <= 2*a[cnt-1]+2) return b[cnt - 1] + 1 + f(cnt - 1, y - 1 - a[cnt - 1] - 1);
	else if (y == a[cnt]) return b[cnt];
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	a[0] = 1;
	b[0] = 1;
	for (int i = 1; i <= n; i++) {
		a[i] = a[i - 1] * 2 + 3;
		b[i] = 2 * b[i - 1] + 1;
	}
	cout << f(n, m);
}