#include <iostream>
using namespace std;

const long long INF = 5e5+7;
long long n, q;
long long a[INF];
long long sumTree[INF * 4], cntTree[INF * 4];

void update(long long tree[], int node, int l, int r, int idx, long long val) {
	if (idx < l || idx > r) return;
	if (l == r) {
		tree[node] += val;
		return;
	}

	tree[node] += val;
	int middle = (l + r) / 2;
	update(tree, node * 2, l, middle, idx, val);
	update(tree, node * 2 + 1, middle + 1, r, idx, val);
}

long long query(long long tree[], int node, int l, int r, int x, int y) {
	if (r < x || l > y) return 0;
	if (x <= l && r <= y) return tree[node];
	int middle = (l + r) / 2;
	return query(tree, node * 2, l, middle, x, y) + query(tree, node * 2 + 1, middle + 1, r, x, y);
}

long long run(long long t) {
	long long l = 0, r = INF - 1;
	long long sum = 0, cnt = 0;

	while (l <= r) {
		long long middle = (l + r) / 2;
		long long temp = query(sumTree, 1, 0, INF - 1, 0, middle);
		if (temp <= t) {
			sum = temp;
			cnt = query(cntTree, 1, 0, INF - 1, 0, middle);
			l = middle + 1;
		} else {
			r = middle - 1;
		}
	}

	if(n>cnt && l < INF) {
		long long rr = query(cntTree, 1, 0, INF - 1, l, l);
		cnt += min(rr, (t - sum) / l);
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		update(cntTree, 1, 0, INF - 1, a[i], 1);
		update(sumTree, 1, 0, INF - 1, a[i], a[i]);
	}

	while (q--) {
		int x;
		cin >> x;
		if (x == 1) {
			long long j, v;
			cin >> j >> v;
			update(cntTree, 1, 0, INF-1, a[j-1], -1);
			update(sumTree, 1, 0, INF-1, a[j-1], -a[j-1]);
			a[j-1] = v;
			update(cntTree, 1, 0, INF-1, v, 1);
			update(sumTree, 1, 0, INF-1, v, v);
		}
		if (x == 2) {
			long long t;
			cin >> t;
			cout << run(t) << "\n";
		}
		if (x == 3) {
			long long v;
			cin >> v;
			a[n++] = v;
			update(cntTree, 1, 0, INF - 1, v, 1);
			update(sumTree, 1, 0, INF - 1, v, v);
		}
	}
}