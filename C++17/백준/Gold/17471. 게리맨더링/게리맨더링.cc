#include <iostream>
#include<vector>
using namespace std;
typedef long long int ll;
const int inf=9876543;
int visited[14];
int visit[14];
ll n,k;
int ans=inf;
int a[100];
vector<int> v1[100];
pair<int,int> f(int x,int y){
  visit[x]=1;
  pair<int,int> m={1,a[x]};
  for(auto t:v1[x]){
    if(visited[t]!=y) continue;
    if(visit[t]) continue;
    pair<int,int> p=f(t,y);
    m.first+=p.first;
    m.second+=p.second;
  }
  return m;
}
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  ll t;
  for(int i=1;i<=n;i++){
    cin>>k;
    for(int j=1;j<=k;j++){
      cin>>t;
      v1[i].push_back(t);
      v1[t].push_back(i);
    }
  }
  for(int i=1;i<(1<<n)-1;i++){
    fill(visited,visited+14,0);
    fill(visit,visit+14,0);
    ll a=-1,b=-1;
    for(int j=0;j<n;j++){
      if(i&(1<<j))visited[j+1]=1,a=j+1;
      else b=j+1;
    }
    pair<int,int> c=f(a,1);
    pair<int,int> d=f(b,0);
    if(c.first+d.first==n) ans=min(ans,abs(c.second-d.second));
  }
  cout<<(ans==inf?-1:ans);
}