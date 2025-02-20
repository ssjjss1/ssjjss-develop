#include<bits/stdc++.h>
#define INF 500004
using namespace std;

int idx;
vector<vector<int>> v, sccGraph, SCC;
vector<int> d, low, cost, sccCost, sccID, rst, dp;
vector<bool> finished;
stack<int> stk;

void dfs(int x){
      d[x] = low[x] = ++idx;
      stk.push(x);
      for(auto node : v[x]){
            if(!d[node]){
                  dfs(node);
                  low[x] = min(low[x], low[node]);
            } else if(!finished[node]){
                  low[x] = min(low[x], d[node]);
            }
      }
      if(low[x] == d[x]){
            vector<int> scc;
            int totalCost = 0;
            while(true){
                  int node = stk.top();
                  stk.pop();
                  finished[node] = true;
                  scc.push_back(node);
                  sccID[node] = SCC.size();
                  totalCost += cost[node];
                  if(node == x) break;
            }
            SCC.push_back(scc);
            sccCost.push_back(totalCost);
      }
}

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int n, m;
      cin >> n >> m;
      
      v.resize(n+1);
      d.assign(n+1, 0);
      low.assign(n+1, 0);
      cost.assign(n+1, 0);
      sccID.assign(n+1, -1);
      finished.assign(n+1, false);
      
      for(int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
      }
      
      for(int i = 1; i <= n; i++) cin >> cost[i];
      
      int s, p;
      cin >> s >> p;
      rst.resize(p);
      for(int i = 0; i < p; i++) cin >> rst[i];
      
      idx = 0;
      for(int i = 1; i <= n; i++){
            if(!d[i]) dfs(i);
      }
      
      sccGraph.resize(SCC.size());
      dp.assign(SCC.size(), INT_MIN);
      vector<int> inDegree(SCC.size(), 0);
      
      for(int i = 1; i <= n; i++){
            for(auto j : v[i]){
                  if(sccID[i] != sccID[j]){
                        sccGraph[sccID[i]].push_back(sccID[j]);
                        inDegree[sccID[j]]++;
                  }
            }
      }
      
      queue<int> q;
      if (sccID[s] != -1) dp[sccID[s]] = sccCost[sccID[s]];
      for(int i = 0; i < SCC.size(); i++){
            if(inDegree[i] == 0) q.push(i);
      }
      
      while(!q.empty()){
            int cx = q.front();
            q.pop();
            for(auto nx : sccGraph[cx]){
                  dp[nx] = max(dp[nx], dp[cx] + sccCost[nx]);
                  if(!--inDegree[nx]) q.push(nx);
            }
      }
      
      int ans = 0;
      for(int i = 0; i < p; i++){
            ans = max(ans, dp[sccID[rst[i]]]);
      }
      cout << ans;
}