#include <bits/stdc++.h>
#define INF 1000000007
using namespace std;

int n, m;
vector<int> A;
pair<int, int> ans[300004];

void Init() {
	for (int i = 1; i <= 300000; i++) {
		ans[i] = {INF, -INF};
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	A.resize(n);

	Init();

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	ans[1] = {0, 0};

	while (m--) {
		int x;
		cin >> x;
		if(ans[x].first==INF) {
			for (int j = 0; j <= 600000; j += x) {
				auto it = lower_bound(A.begin(), A.end(), j);

				if (it != A.end()) {
					ans[x].first = min(ans[x].first, (*it % x));
					ans[x].second = max(ans[x].second, (*it % x));
				}
				if (it != A.begin()) {
					it--;
					ans[x].first = min(ans[x].first, (*it % x));
					ans[x].second = max(ans[x].second, (*it % x));
				}
			}
		}
		cout << ans[x].first << " " << ans[x].second << "\n";
	}
}