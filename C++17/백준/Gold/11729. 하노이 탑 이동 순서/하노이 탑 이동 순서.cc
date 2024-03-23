#include<iostream>
#include<cmath>
using namespace std;
long long int n,ans;
void f(int n, int a, int b, int c) {
	if (n == 1) {
		cout << a << " " << c<<"\n";
		return;
	}
	f(n - 1, a, c, b);
	cout << a << " " << c<<"\n";
	f(n - 1, b, a, c);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	ans=pow(2, n) - 1;
	cout << ans<<"\n";
	f(n, 1, 2, 3);
}