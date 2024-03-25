#include<iostream>

using namespace std;

int n, x, y;

int a[30];

int ans = 0;

void f(int cnt) {

	if (cnt == n+1) {		ans += 1;

		return;

	}

	if (cnt == y - x - 1) f(cnt + 1);

	for (int j = 1; (j+cnt+1) < 2*n+1; j++) {

		if (a[j] == 0 && a[j + cnt + 1] == 0) {

			a[j] = cnt;

			a[j + cnt + 1] = cnt;

			f(cnt + 1);

			a[j] = 0;

			a[j + cnt + 1] = 0;

		}

	}

}

int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> x >> y;

	a[x] = y - x - 1, a[y] = y - x - 1;

	f(1);

	cout << ans;

}