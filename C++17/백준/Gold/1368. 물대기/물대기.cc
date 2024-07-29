#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int a[304],d[304];
int visited[304];
bool compare(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
  return a.second<b.second;
}
int f(int x){
  if(d[x]==x) return x;
  return d[x]=f(d[x]);
}
vector<pair<pair<int,int>,int>> v;
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++) d[i]=i;
  for(int i=1,x;i<=n;i++) cin>>x, v.push_back({{0,i},x});
  for(int i=1;i<=n;i++){
    for(int j=1,x;j<=n;j++){
      cin>>x;
      if(i>j) continue;
      if(i!=j) v.push_back({{i,j},x});
    }
  }
  sort(v.begin(),v.end(),compare);
  int ans=0;
  for(auto i:v){
    int x=i.first.first, y=i.first.second, w=i.second;
    int X=f(x),Y=f(y);
    if(X!=Y) {
      d[X]=Y;
      ans+=w;
    }
  }
  cout<<ans;
}