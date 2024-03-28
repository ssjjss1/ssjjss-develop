#include<iostream>
using namespace std;
long long int a[1001][1001];
long long int n, m;
long long int f(int x, int y) {
	if (y == 0) { a[x][y] = 1; return 1; }
	if (a[x][y] != 0) return a[x][y]%10007;
	if (x == y) {
		a[x][y] = 1;
		return 1;
	}
	if (y == 1) {
		a[x][y] = x;
		return x;
	}
	return a[x][y] =(f(x - 1, y - 1) + f(x - 1, y)) % 10007;

}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	f(n, m);
	cout << a[n][m];
}