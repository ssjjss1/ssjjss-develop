#include<iostream>
#include<vector>
#include<climits>
#define INF 100004
using namespace std;
vector<int> a(INF);

struct T {
	long long mn, mx, diff;
	T() {}
	T(long long mn, long long mx, long long diff) : mn(mn), mx(mx), diff(diff) {}
};

T tree[INF * 4];

void update(int node, int l, int r, int x, int val) {
	if (l == r) {
		tree[node] = T(val, val, 0);
		return;
	}

	int middle = (l + r) / 2;
	if (x <= middle) {
		update(node * 2, l, middle, x, val);
	} else {
		update(node * 2 + 1, middle + 1, r, x, val);
	}

	T left = tree[node * 2];
	T right = tree[node * 2 + 1];

	tree[node] = T(
	                 min(left.mn, right.mn),
	                 max(left.mx, right.mx),
	                 max(right.mx - left.mn, max(left.diff, right.diff))
	             );
}

T query(int node, int l, int r, int x, int y) {
	if (r < x || y < l) {
		return T(INT_MAX, -INT_MAX, 0);
	}
	if (x <= l && r <= y) {
		return tree[node];
	}

	int middle = (l + r) / 2;
	T left = query(node * 2, l, middle, x, y);
	T right = query(node * 2 + 1, middle + 1, r, x, y);

	return T(
	           min(left.mn, right.mn),
	           max(left.mx, right.mx),
	           max(right.mx - left.mn, max(left.diff, right.diff))
	       );
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(1, 1, n, i, a[i]);
	}

	cin >> q;
	while (q--) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int k, x;
			cin >> k >> x;
			update(1, 1, n, k, x);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << query(1, 1, n, l, r).diff << '\n';
		}
	}
}