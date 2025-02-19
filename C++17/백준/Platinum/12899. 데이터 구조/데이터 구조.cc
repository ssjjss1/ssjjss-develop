#include <bits/stdc++.h>
#define INF 2000004
using namespace std;

int n;
int t[INF * 4];

void update(int node, int l, int r, int x, int val) {
	if (l == r) {
		t[node] += val;
		return;
	}
	int middle = (l + r) / 2;
	if (middle >= x) update(node * 2, l, middle, x, val);
	else update(node * 2 + 1, middle + 1, r, x, val);
	t[node] = t[node * 2] + t[node * 2 + 1];
}

int query(int node, int l, int r, int cnt) {
	if (l == r) return l;
	int left_cnt = t[node * 2];
	int middle = (l + r) / 2;
	if (left_cnt >= cnt) return query(node * 2, l, middle, cnt);
	else return query(node * 2 + 1, middle + 1, r, cnt - left_cnt);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int mode, x;
		cin >> mode >> x;
		if (mode == 1) {
			update(1, 1, INF - 1, x, 1);
		} else {
			int res=query(1, 1, INF - 1, x);
			cout << res << '\n';
			update(1, 1, INF - 1, res, -1);
		}
	}
}