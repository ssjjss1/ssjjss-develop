#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int, int> pii;

#define INF 100000

int n;
pii P[INF];
vector<pii> a, b;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> P[i].first >> P[i].second;
	}

	sort(P, P + n);

	auto isCross = [](const pii& x, const pii& y) {
		return (x.first < y.first) != (x.second < y.second);
	};

	{
		int prev = -1;
		for (int i = 0; i < n; ++i) {
			if (prev == -1 || !isCross(P[prev], P[i])) {
				a.push_back(P[i]);
				prev = i;
			}
			else {
				b.push_back(P[i]);
			}
		}
	}

	auto run = [&](vector<pii>& A, vector<pii>& B) {
		int mx = 1;
		int ai = 0, bi = 0;

		while (ai < (int)A.size() && bi < (int)B.size()) {
			if (isCross(A[ai], B[bi])) {
				int cnt = 2;
				int tempA = ai, tempB = bi;
				bool flag = true;

				while (true) {
					if (flag) {
						if (tempB + 1 < (int)B.size() && isCross(A[tempA], B[tempB + 1])) {
							tempB++;
							cnt++;
							flag = false;
						}
						else if (tempA + 1 < (int)A.size() && isCross(A[tempA + 1], B[tempB])) {
							tempA++;
						}
						else break;
					}
					else {
						if (tempA + 1 < (int)A.size() && isCross(A[tempA + 1], B[tempB])) {
							tempA++;
							cnt++;
							flag = true;
						}
						else if (tempB + 1 < (int)B.size() && isCross(A[tempA], B[tempB + 1])) {
							tempB++;
						}
						else break;
					}
				}

				mx = max(mx, cnt);
				ai = tempA + 1;
				bi = tempB + 1;
			}
			else {
				if (A[ai].first < B[bi].first) ai++;
				else bi++;
			}
		}
		return mx;
	};

	int ans = max(run(a, b), run(b, a));
	cout << ans;
}