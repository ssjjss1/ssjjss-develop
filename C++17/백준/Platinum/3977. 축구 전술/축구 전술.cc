#include <bits/stdc++.h>
#define INF 100004
using namespace std;

int idx;
stack<int> stk;
vector<int> v[INF];
vector<int> d, low;
vector<bool> finished;
vector<vector<int>> SCC;

void dfs(int x) {
    d[x] = low[x] = ++idx;
    stk.push(x);
    for (auto node : v[x]) {
        if (!d[node]) {
            dfs(node);
            low[x] = min(low[x], low[node]);
        } else if (!finished[node]) {
            low[x] = min(low[x], d[node]);
        }
    }
    
    if (low[x] == d[x]) {
        vector<int> scc;
        while (true) {
            int node = stk.top();
            stk.pop();
            scc.push_back(node);
            finished[node] = true;
            if (node == x) break;
        }
        SCC.push_back(scc);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        for (int i = 0; i < n; i++) v[i].clear();
        d.assign(n, 0);
        low.assign(n, 0);
        finished.assign(n, false);
        SCC.clear();
        idx = 0;
        
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
        }
        
        for (int i = 0; i < n; i++) {
            if (!d[i]) dfs(i);
        }
        
        vector<int> ind(n, -1);
        unordered_map<int, vector<int>> ans;
        for (auto &scc : SCC) {
            for (auto node : scc) {
                ind[node] = scc[0];
                ans[scc[0]] = scc;
            }
        }
        
        vector<int> inDegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto j : v[i]) {
                if (ind[i] != ind[j]) inDegree[ind[j]]++;
            }
        }
        
        vector<vector<int>> res;
        for (auto &scc : SCC) {
            if (inDegree[scc[0]] == 0) {
                res.push_back(ans[scc[0]]);
            }
        }
        
        if (res.empty() || res.size() > 1) {
            cout << "Confused\n";
        } else {
            vector<int> Scc = res[0];
            sort(Scc.begin(), Scc.end());
            for (auto node : Scc) {
                cout << node << '\n';
            }
        }
        cout << "\n";
    }
}