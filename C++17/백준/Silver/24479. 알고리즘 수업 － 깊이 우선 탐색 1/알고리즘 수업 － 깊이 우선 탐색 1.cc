#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt;
vector<int> v[100004];
vector<int> visited(100004,0);
void dfs(int x){
      visited[x]=++cnt;
      for(auto i:v[x]) if(!visited[i]) dfs(i);
}

int main(){
      ios_base::sync_with_stdio(0); cin.tie(0);
      cin>>n>>m>>k;
      for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
      }
      
      for(int i=1;i<=n;i++){
            sort(v[i].begin(), v[i].end());
      }
      
      dfs(k);
      
      for(int i=1;i<=n;i++) cout<<visited[i]<<"\n";
}