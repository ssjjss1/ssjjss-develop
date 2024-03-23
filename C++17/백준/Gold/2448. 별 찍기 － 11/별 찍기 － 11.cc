#include<iostream>
using namespace std;
int n;
char c[10001][10001];
void f(int x, int y, int cnt) {
	if (cnt == 3) {
		c[x][y] = '*';
		c[x + 1][y + 1] = '*';
		c[x + 1][y - 1] = '*';
		for (int i = 0; i <= 2; i++) {
			c[x + 2][y - i] = '*';
			c[x + 2][y + i] = '*';
		}
	}
	else {
		f(x, y, cnt / 2);
		f(x + cnt / 2, y - cnt / 2, cnt / 2);
		f(x + cnt / 2, y + cnt / 2, cnt / 2);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	f(0, n - 1, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			if (c[i][j] == '*') cout << c[i][j];
			else cout << ' ';
		}
		cout << "\n";
	}
}