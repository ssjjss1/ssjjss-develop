#include <bits/stdc++.h>
#define INF 1000000007
using namespace std;

int n, k, idx;
int dp[1004][1004];
vector<int> d(1004, 0), low(1004, 0), scc_size(1004, 0);
vector<bool> finished(1004, false);
vector<vector<int>> SCC(1004); 
vector<int> v[1004];         
stack<int> stk;

void f(int x) {
    d[x] = low[x] = ++idx;
    stk.push(x);
    
    for (auto node : v[x]) {
        if (!d[node]) {
            f(node);
            low[x] = min(low[x], low[node]);  
        } else if (!finished[node]) {
            low[x] = min(low[x], d[node]); 
        }
    }
    
    if (low[x] == d[x]) {
        int Size = 0;
        while (true) {
            int node = stk.top();
            stk.pop();
            finished[node] = true;
            low[node] = low[x]; 
            Size++;
            if (node == x) break;
        }
        scc_size[low[x]] = Size;
    }
}

int sum = 0;
vector<bool> visited(1004, false);
void dfs(int x) {
    visited[x] = true;
    sum += scc_size[x];
    for (auto nxt : SCC[x]) {
        if (!visited[nxt])
            dfs(nxt);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x == i) continue;
        v[x].push_back(i);
    }
    
    for (int i = 1; i <= n; i++){
        if (!d[i]) f(i);
    }

    for (int i = 1; i <= n; i++){
        for (auto j : v[i]){
            if (low[i] != low[j])
                SCC[low[i]].push_back(low[j]);
        }
    }
    
    vector<int> inDegree(1004, 0);
    for (int i = 1; i <= n; i++){
        for (auto j : SCC[i])
            inDegree[j]++;
    }
    
    vector<int> start;
    for (int i = 1; i <= n; i++){
        if (scc_size[i] > 0 && inDegree[i] == 0)
            start.push_back(i);
    }
    
    vector<pair<int,int>> mn_mx;
    for (auto s : start) {
        fill(visited.begin(), visited.end(), false);
        sum = 0;
        dfs(s);
        mn_mx.push_back({ scc_size[s], sum });
    }
    
    int m = mn_mx.size();
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    
    for (int i = 1; i <= m; i++){
        int a = mn_mx[i-1].first, b = mn_mx[i-1].second;
        for (int j = 0; j <= k; j++){
            if (dp[i-1][j]) {
                dp[i][j] = 1;
                for (int x = a; x <= b; x++){
                    if(j + x <= k)
                        dp[i][j + x] = 1;
                }
            }
        }
    }
    
    int ans = 0;
    for (int j = 0; j <= k; j++){
        if (dp[m][j]) ans = max(ans, j);
    }
    
    cout << ans;
}