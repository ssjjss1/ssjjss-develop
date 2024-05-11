#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
long long int n,m,a;
long long int x,y;
int visited[100001];
int visit[1000001];
vector<int> v[100000];
void f(int t){
  visited[t]=1;
  cout<<t<<" ";
  for(auto i:v[t]){
    if(visited[i]==0) f(i);
  }
  return;
}
void g(int a){
  queue<int> q;
  visit[a]=1;
  q.push(a);
  while(q.size()){
    int a=q.front();
    q.pop();
    cout<<a<<" ";
    for(int t:v[a]){
      if(visit[t]) continue;
      visit[t]=true;
      q.push(t);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m>>a;
  for(int i=1;i<=m;i++){
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for(int i=1;i<=n;i++){
    sort(v[i].begin(),v[i].end());
  }
  f(a);
  cout<<"\n";
  g(a);
}