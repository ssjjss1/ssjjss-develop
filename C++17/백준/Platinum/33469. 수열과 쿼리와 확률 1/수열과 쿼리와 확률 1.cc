#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long fpow(long long b, long long e, long long mod) {
	long long res = 1;
	while (e > 0) {
		if (e % 2) res = res * b % mod;
		b = b * b % mod;
		e /= 2;
	}
	return res;
}

long long finv(long long x, long long mod) {
	return fpow(x, mod - 2, mod);
}

long long fac(long long n, long long mod) {
	long long res = 1;
	for (long long i = 2; i <= n; i++) {
		res = res * i % mod;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n, m;
	cin >> n >> m;

	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	char q;
	cin >> q;

	if (q == 'S') {
		cout << 1;
	}
	else if (q == 'P') {
		long long facN = fac(n, MOD);
		facN /= 2;
		long long powN = fpow(n, n, MOD);
		long long num = (facN + powN) % MOD;
		long long inV = finv(powN, MOD);
		long long r = num * inV % MOD;
		long long res = fpow(r, m, MOD);
		cout << res;
	}
}