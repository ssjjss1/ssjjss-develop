#include<bits/stdc++.h>
using namespace std;
int n,m,t;
vector<int> adj[200004], v1[200004], v2[200004];
int visited[200004];

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cin>>n>>m>>t;
      
      for(int i=1;i<=n;i++){
            int x,y;
            cin>>x>>y;
            
            v1[x].push_back(i);
            v2[y-1].push_back(i);
      }
      
      for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            
            adj[x].push_back(y);
            adj[y].push_back(x);
      }
      
      int cnt=0;
      for(int i=0;i<t;i++){
            for(auto j:v1[i]){
                  visited[j]=1;
                  for(auto k:adj[j]){
                        if(visited[k]){
                              cnt+=1;
                        }
                  }
            }
            
            cout<<cnt<<"\n";
            
            for(auto j:v2[i]){
                  visited[j]=0;
                  for(auto k:adj[j]){
                        if(visited[k]){
                              cnt-=1;
                        }
                  }
            }
      }
      
}