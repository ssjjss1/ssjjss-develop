#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	unordered_map<int, int> counts;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		counts[a[i]]++;
	}

	int max_unique = -1, index = -1;
	for (int i = 0; i < n; i++) {
		if (counts[a[i]] == 1 && a[i] > max_unique) {
			max_unique = a[i];
			index = i + 1;
		}
	}

	if (index != -1) cout << index;
	else cout << "none";
}