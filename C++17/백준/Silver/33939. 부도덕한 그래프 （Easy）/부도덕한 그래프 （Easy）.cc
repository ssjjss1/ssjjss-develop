#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[2004];       
vector<int> rev_adj[2004];   
bitset<2004> isEdge[2004]; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
        isEdge[u][v] = 1;
    }

    long long res = 0;

    for (int z = 1; z <= n; z++) {
        const vector<int>& p = rev_adj[z];
        int size = p.size();
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                int x = p[i], y = p[j];
                if (!isEdge[x][y] && !isEdge[y][x]) {
                    res+=1;
                }
            }
        }
    }

    cout << res;
}