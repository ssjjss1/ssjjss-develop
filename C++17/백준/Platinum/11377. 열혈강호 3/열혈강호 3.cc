#include<bits/stdc++.h>
using namespace std;
int n,m,k;

vector<int> visited;
vector<int> A(1004,-1), B(1004,-1);
vector<int> adj[1004];

bool dfs(int a){
      visited[a]=1;
      
      for(auto b:adj[a]){
            if(B[b]==-1||(!visited[B[b]]&&dfs(B[b]))){
                  A[a]=b;
                  B[b]=a;
                  return true;
            }
      }
      return false;
}

int bipartite_matching(){
      int cnt=0;
      for(int i=1;i<=n;i++){
            visited.assign(1004, 0);
            if(dfs(i)) cnt+=1;
      }
      
      for(int i=1;i<=n && k>0;i++){
            visited.assign(1004, 0);
            if(dfs(i)){
                  cnt+=1;
                  k-=1;
            }
      }
      
      return cnt;
}

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cin>>n>>m>>k;
      
      for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            for(int j=1;j<=x;j++){
                  int y;
                  cin>>y;
                  
                  adj[i].push_back(y);
            }
      }
      
      cout<<bipartite_matching();
}