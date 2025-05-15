#include <bits/stdc++.h>
using namespace std;

int t;
vector<int> A, B;
vector<int> adj[504];
vector<bool> visited;

bool dfs(int a) {
    for (auto b : adj[a]) {
        if(visited[b]) continue;
        visited[b] = true;
        if (B[b] == -1 || dfs(B[b])) {
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}

int bipartite_matching(int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		visited.assign(n+4, 0);
		if (dfs(i)) cnt+=1;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<long long> height(n+4);
		vector<string> music(n+4), sports(n+4);
		vector<int> male, female;

		for (int i = 0; i < n; i++) {
			char MF;
			
			cin >> height[i] >> MF >> music[i] >> sports[i];
			if (MF == 'M') male.push_back(i);
			else female.push_back(i);
		}

		for (int i = 0; i < 504; i++) adj[i].clear();

		A.assign(n+4, -1);
		B.assign(n+4, -1);
		for (int i = 0; i < male.size(); i++) {
			for (int j = 0; j < female.size(); j++) {
				int m = male[i], f = female[j];
				if (abs(height[m] - height[f]) <= 40 &&
				        music[m] == music[f] &&
				        sports[m] != sports[f]) {
					adj[i].push_back(j);
				}
			}
		}

		cout << n - bipartite_matching(male.size()) << "\n"; 
		//n - (조건을 만족하지 못하는 모든 경우!)
	}
}