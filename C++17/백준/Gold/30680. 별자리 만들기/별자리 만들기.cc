#include<bits/stdc++.h>
using namespace std;
int n;
vector<bool> visited(100004, 0);
vector<int> leaf;
int inDegree[100004];

void dfs(int x, int dep, vector<int> adj[]) {
      if(inDegree[x] == 1) {
            leaf.push_back(dep);
            return;
      }
      
      for(auto i : adj[x]) {
            if(!visited[i]) {
                  visited[i] = true;
                  dfs(i, dep + 1, adj);
            }
      }
}

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      cin >> n;
      priority_queue<int, vector<int>, greater<int>> pq;
      
      for(int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            
            memset(inDegree, 0, (x + 1) * sizeof(int));
            
            vector<int> adj[x + 1];
            
            for(int j = 0; j < x - 1; j++) {
                  int u, v;
                  cin >> u >> v;
                  
                  adj[u].push_back(v);
                  adj[v].push_back(u);
                  inDegree[u]++;
                  inDegree[v]++;
            }
            
            inDegree[1] = 2;
            
            fill(visited.begin(), visited.begin() + x + 1, false);
            visited[1] = true;
            leaf.clear();
            dfs(1, 1, adj);
            
            int root = 0;
            if(!pq.empty()) {
                  root = pq.top();
                  pq.pop();
            }
            
            for(auto j : leaf) {
                  pq.push(root + j);
            }
      }
      
      int ans = 0;
      while(!pq.empty()) {
            ans = pq.top();
            pq.pop();
      }
      
      cout << ans;
}