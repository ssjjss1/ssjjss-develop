#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string> d(n);
		for (int i = 0; i < n; i++) {
			cin >> d[i];
		}

		bool flag = true;

		for (int i = n - 1; i > 0; i--) {
			for (int j = 0; j < m - 1; j++) {
				if (d[i][j] != '.') continue;

				if (d[i][j + 1] == '.') {
					int idx = j;
					while (idx > 0 && d[i - 1][idx - 1] == '.') {
						idx--;
					}

					if (d[i - 1][j] == '.' && (j - idx) % 2 == 0) {
						d[i - 1][j] = d[i][j] = d[i][j + 1] = 'a';
					}
					else if (j + 1 < m && d[i - 1][j + 1] == '.') {
						d[i - 1][j + 1] = d[i][j] = d[i][j + 1] = 'b';
					} 
					else {
						flag = false;
						break;
					}
				} else {
					flag = false;
					break;
				}
			}
			if (!flag) break;
		}

		if (flag) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (d[i][j] == '.') {
						flag = false;
						break;
					}
				}
				if (!flag) break;
			}
		}

		if (flag) {
			for (auto &row : d) {
				cout << row << "\n";
			}
		} else {
			cout << "-1\n";
		}
	}
}