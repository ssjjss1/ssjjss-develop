#include<bits/stdc++.h>
using namespace std;
uint64_t f(__int128_t x, __int128_t y, __int128_t c) {
	if (y == 1) return x % c;
	__int128_t a = f(x, y / 2, c);
	a = (a * a) % c;
	if (y % 2 == 1) a = (a * x) % c;
	return a;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	uint64_t a, b, c;
	cin >> a >> b >> c;
	cout << f(a, b, c);
}