#include<iostream>
using namespace std;
int n;
int a[200001];
int g(int x, int y) {
	if (y == 0) return x;
	else return g(y, x % y);
}
int f(int l, int r) {
	if (r == l) return a[l];
	int middle = (r + l-1) / 2;
	int b = 0, c = 0;
	for (int i = l; i <= middle; i++) {
		b=g(b, a[i]);
	}
	for (int i = middle+1; i <= r; i++) {
		c=g(c, a[i]);
	}
	return max(b+f(middle + 1, r), c+f(l, middle));
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << f(0, n-1);//l,r
}