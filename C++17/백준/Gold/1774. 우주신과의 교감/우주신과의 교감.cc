#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
typedef long long ll;
const ll inf=1e18+4;
int n,m;
ll mn[1004][1004];
int d[1004];
bool compare(pair<pair<ll,ll>,ll> a, pair<pair<ll,ll>,ll> b){return a.second<b.second;}
int f(int x) {
  if(x==d[x]) return x;
  return d[x]=f(d[x]);
}
void g(int x, int y){
  int X=f(x),Y=f(y);
  if(X!=Y) d[X]=Y;
}
vector<pair<ll,ll>> v;
vector<pair<pair<ll,ll>,ll>> v1;
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++) d[i]=i;
  for(int i=1,x,y;i<=n;i++) {
    cin>>x>>y;
    v.push_back({x,y});
  } 
  for(int i=1,x,y;i<=m;i++) cin>>x>>y, g(--x,--y);
  for(int i=0;i<=1000;i++)
    for(int j=0;j<=1000;j++)
      mn[i][j]=inf;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j) continue;
      int x1=v[i].first,y1=v[i].second, x2=v[j].first,y2=v[j].second;
      mn[i][j]=min(mn[i][j],(ll)(x1-x2)*(x1-x2)+(ll)(y1-y2)*(y1-y2));
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(mn[i][j]!=inf) v1.push_back({{i,j},mn[i][j]});
    }
  }
  sort(v1.begin(),v1.end(),compare);
  double ans=0;
  for(auto i:v1){
    int x=i.first.first, y=i.first.second;
    ll w=i.second;
    if(f(x)!=f(y)) g(x,y), ans+=sqrt(w);
  }
  cout<<fixed<<setprecision(2)<<ans<<endl;
}