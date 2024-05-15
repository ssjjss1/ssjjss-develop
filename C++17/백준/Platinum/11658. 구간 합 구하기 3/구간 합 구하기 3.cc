#include<iostream>
using namespace std;
int n, m;
int a[1025][1025];
int b[1025][1025];
void f(int x, int y, int k) {
	while (x <= n) {
		int yy = y;
		while (yy <= n) {
			b[x][yy] += k;
			yy += (yy & -yy);
		}
		x += (x & -x);
	}
	return;
}
long long g(int x, int y) {
	long long sum = 0;
	while (x > 0) {
		int yy = y;
		while (yy > 0) {
			sum += b[x][yy];
			yy -= (yy & -yy);
		}
		x -= (x & -x);
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			f(i, j, a[i][j]);
		}
	}
	while (m--) {
		int cnt, x, y, x1, y1;
		cin >> cnt;
		if (cnt == 1) {
			cin >> x >> y >> x1 >> y1;
			cout << g(x1, y1) - g(x1, y - 1) - g(x - 1, y1) + g(x - 1, y - 1) << "\n";
		}
		else {
			cin >> x >> y >> y1;
			f(x, y, y1 - a[x][y]);
			a[x][y] = y1;
		}
	}
}