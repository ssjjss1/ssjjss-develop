#include <bits/stdc++.h>
#define INF 1004
using namespace std;

int n, m;
vector<int> v[INF];
vector<bool> visited;
vector<int> A(INF, -1), B(INF, -1);

bool dfs(int a) {
    visited[a] = true;
    for (auto b : v[a]) {
        if (B[b] == -1 || (!visited[B[b]] && dfs(B[b]))) {
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}

int bipartite_matching() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            visited.assign(n + 4, false);
            if (dfs(i)) cnt+=1;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int u;
            cin >> u;
            v[i].push_back(u);
        }
    }

    cout << bipartite_matching();
}