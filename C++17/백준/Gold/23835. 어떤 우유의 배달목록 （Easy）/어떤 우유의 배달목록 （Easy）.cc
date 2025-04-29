#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1004];
int milk[1004];
bool visited[1004];

bool dfs(int a, int b, int cnt) {
    if (a == b) {
        return true;
    }
    
    for (auto i : adj[a]) {
        if (!visited[i]) {
            visited[i] = true;
            if (dfs(i, b, cnt + 1)) {
                milk[i] += cnt;
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cin >> m;
    
    while (m--) {
        int t;
        cin >> t;
        
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            
            memset(visited, 0, sizeof(visited));
            visited[a] = true;
            dfs(a, b, 1);
        } else {
            int a;
            cin >> a;
            cout << milk[a] << "\n";
        }
    }
}