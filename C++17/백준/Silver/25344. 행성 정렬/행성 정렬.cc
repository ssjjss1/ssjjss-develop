#include<iostream>
using namespace std;
typedef long long int ll;
ll a, b, c = 1;
ll g(ll x, ll y) {
	if (y == 0) return x;
	return g(y, x % y);
}
ll f(ll x ,ll y) {
	return x * y / g(x, y);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a;
	for (int i = 1; i <= a - 2; i++) {
		cin >> b;
		c = f(b, c);
	}
	cout << c;
}