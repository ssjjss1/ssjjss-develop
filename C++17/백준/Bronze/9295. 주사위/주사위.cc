#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >>t;
	for (int i = 1,x,y; i <= t; i++) {
		cin >> x >> y;
		cout << "Case " << i << ": " << x + y << "\n";
	}
}