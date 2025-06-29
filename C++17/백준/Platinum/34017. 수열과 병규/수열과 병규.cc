#include <bits/stdc++.h>
using namespace std;

// long long run1(long long n) {
// 	if (d.count(n)) return d[n];
// 	if (n == 1) return d[n] = 1;
// 	if (n == 2) return d[n] = 2;

// 	long long res;
// 	if (n % 3 == 0) {
// 		long long x = n / 3;
// 		res = 2 * run1(x) + 2 * run1(x + 1) + 1;
// 	} else if (n % 3 == 1) {
// 		long long x = n / 3;
// 		res = 2 * run1(x + 2) - 1;
// 	} else {
// 		long long x = n / 3;
// 		res = -2 * run1(x + 1) - 2 * run1(x + 2) + 2;
// 	}

// 	return d[n] = res;
// }

long long run2(long long n) {
	if(n==1) return 1;
	if(n==2) return 3;
	if(n==3) return 10;     
	
	if(n%3==1) return 2*run2(n/3+2)+2*(n/3)+1;
	if(n%3==0) return 2*run2(n/3+1)+2*(n/3)+2;
	if(n%3==2) return 2*run2(n/3)+2*(n/3)+3;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;

	while (q--) {
		long long n;
		cin >> n;
		cout << run2(n) << '\n';
	}
}