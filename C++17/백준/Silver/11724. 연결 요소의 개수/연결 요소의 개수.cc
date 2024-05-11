#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n,m;
int x,y;
int visited[1001];
vector<int> v[1001];
void f(int x){
  visited[x]=1;
  queue<int> q;
  q.push(x);
  while(!q.empty()){
    int xx=q.front();
    q.pop();
    for(int i=0;i<v[xx].size();i++){
      if(visited[v[xx][i]]) continue;
      visited[v[xx][i]]=1;
      q.push(v[xx][i]);
    }
  }
}
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    if(!visited[i]){
      ans+=1;
      f(i);
    }
  }
  cout<<ans;
}