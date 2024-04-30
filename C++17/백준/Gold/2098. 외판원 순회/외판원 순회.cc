#include<bits/stdc++.h>
using namespace std;
const int inf = 987654321;
int n;
int a[16][16];
int dp[16][1<<16];
int f(int x, int cnt) {
	if (cnt == (1 << n) - 1) return a[x][0] == 0 ? inf : a[x][0];
	int &ref = dp[x][cnt];
	if (ref != -1) return ref;
	ref = inf;
	for (int i = 0; i < n; i++) {
		if (!a[x][i]||cnt & (1 << i)) continue;
		ref = min(ref, f(i, cnt | (1 << i)) + a[x][i]);
	}
	return ref;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << f(0,1);
}