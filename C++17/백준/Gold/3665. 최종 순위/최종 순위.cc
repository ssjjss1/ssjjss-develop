#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int t;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>t;
      while(t--){
            int n,m;
            cin>>n;
            vector<int> v(n+4), in(n+4,0), ans;
            vector<vector<int>> adj(n+4, vector<int>(n+4,0));
            for(int i=1;i<=n;i++) cin>>v[i];
            for(int i=1;i<=n;i++) {
                  for(int j=i+1;j<=n;j++){
                        adj[v[i]][v[j]]=1;
                        in[v[j]]+=1;
                  }
            }
            cin>>m;
            for(int i=1,x,y;i<=m;i++){
                  cin>>x>>y;
                  if(adj[x][y]){
                        in[x]+=1;in[y]-=1;
                        adj[x][y]=0;adj[y][x]=1;
                  }
                  else{
                        in[y]+=1;in[x]-=1;
                        adj[y][x]=0;adj[x][y]=1;
                  }
            }
            queue<int> q;
            bool flag=true;
            for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
            for(int i=1;i<=n;i++){
                  if(q.empty()){
                        cout<<"IMPOSSIBLE";
                        flag=false;
                        break;
                  }
                  if(q.size()>1){
                        cout<<"?";
                        flag=false;
                        break;
                  }
                  int x=q.front();
                  q.pop();
                  ans.push_back(x);
                  for(int j=1;j<=n;j++){
                        if(adj[x][j]){
                              if(!--in[j]) q.push(j);
                        }
                  }
            }
            if(flag) for(auto i:ans) cout<<i<<" ";
            cout<<"\n";
      }
}