#include<bits/stdc++.h>
using namespace std;

int n, b, w, ans;
string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> b >> w >> s;

	int l = 0, r = 0, cntb = 0, cntw = 0;

	while (r < n) {
		if (s[r] == 'B') cntb+=1;
		else cntw+=1;

		while (cntb > b) {
			if (s[l] == 'B') cntb-=1;
			else cntw-=1;
			l+=1;
		}

		if (cntw >= w) ans = max(ans, r - l + 1);

		r+=1;
	}

	cout << ans;
}