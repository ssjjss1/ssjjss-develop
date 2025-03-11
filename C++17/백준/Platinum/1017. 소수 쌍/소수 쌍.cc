#include <bits/stdc++.h>
#define INF 2004
using namespace std;

int n;
vector<int> v[INF], even, odd, A(INF), B(INF);
vector<bool> at(INF, 0), visited(INF, 0);

bool dfs(int a) {
	visited[a] = 1;
	for (auto b : v[a]) {
		if (B[b] == -1 || (!visited[B[b]] && dfs(B[b]))) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

bool bipartite_matching(int x) {
	int cnt = 0;
	A.assign(INF, -1);
	B.assign(INF, -1);
	A[0] = x;
	B[x] = 0;

	for (int i = 1; i < odd.size(); i++) {
		visited.assign(INF, 0);
		visited[0] = 1;
		if (dfs(i)) cnt++;
	}
	return cnt == even.size() - 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool flag=true;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(i==0&&x%2) flag=false;
		if (x % 2) odd.push_back(x);
		else even.push_back(x);
	}

	vector<int> ans;

	if (odd.size() != even.size()) {
		cout << -1;
		return 0;
	}

	for (int i = 2; i < INF; i++) {
		if (!at[i]) {
			for (int j = 2 * i; j < INF; j += i) {
				at[j] = 1;
			}
		}
	}

	if(flag) swap(odd, even);

	for (int i = 0; i < odd.size(); i++) {
		for (int j = 0; j < even.size(); j++) {
			if (!at[odd[i] + even[j]]) {
				v[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < even.size(); i++) {
		if(!at[odd[0]+even[i]]) {
			if (bipartite_matching(i)) {
				ans.push_back(even[i]);
			}
		}
	}

	if (ans.empty()) {
		cout << -1;
	} else {
		sort(ans.begin(), ans.end());
		for (auto i : ans) cout << i << " ";
	}
}