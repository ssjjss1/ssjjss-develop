#include<iostream>
using namespace std;
int n, x, y;
int cnt;
int a[1000][1000];
int visited(int x, int y, int size) {
	for (int i = x; i < x + size ; i++) {
		for (int j = y; j < y + size; j++) {
			if (a[i][j] != 0) return 0;
		}
	}
	return 1;
}
void f(int x, int y, int size) {
	cnt += 1;
	if (visited(x, y, size / 2)) a[x + size / 2 - 1][y + size / 2 - 1] = cnt;
	if (visited(x, y + size / 2, size / 2)) a[x + size / 2 - 1][y + size / 2] = cnt;
	if (visited(x + size / 2, y, size / 2)) a[x + size / 2][y + size / 2 - 1] = cnt;
	if (visited(x + size / 2, y + size / 2, size / 2)) a[x + size / 2 ][y + size / 2] = cnt;
	if (size == 2) return;
	f(x, y, size/2);
	f(x + size/2, y, size / 2);
	f(x, y + size/2, size / 2);
	f(x + size/2, y + size/2, size / 2);
}
int main() {
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	cin >> n >> x >> y;
	a[y][x] = -1;
	f(1, 1,1<<n);
	for (int i = (1 << n); i >= 1; i--) {
		for (int j = 1; j <= (1 << n); j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}