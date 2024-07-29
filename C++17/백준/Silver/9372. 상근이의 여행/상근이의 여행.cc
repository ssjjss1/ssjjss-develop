#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int t;
int visited[1004];
vector<int> v[10004];
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    fill(visited,visited+1004,0);
    for(int i=1;i<=n;i++) v[i].clear();
    for(int i=1,x,y;i<=m;i++) cin>>x>>y, v[x].push_back(y),v[y].push_back(x);
    int ans=0;
    queue<int> q;
    visited[1]=1;
    q.push(1);
    while(!q.empty()){
      int x=q.front();
      q.pop();
      for(auto i:v[x]){
        if(!visited[i]){
          visited[i]=1;
          ans+=1;
          q.push(i);
        }
      }
    }
    cout<<ans<<"\n";
  }
}