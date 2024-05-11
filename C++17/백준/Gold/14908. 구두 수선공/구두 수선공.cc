#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
struct P{float f;int a,b,c;};
bool compare(const P &x,const P &y){
  if(x.f==y.f){
    return x.c<y.c;
  }
  return x.f>y.f;
}
vector<P> v;
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++){
    int x,y;
    cin>>x>>y;
    v.push_back({float(y)/float(x),x,y,i});
  }
  sort(v.begin(),v.end(),compare);
  for(int i=0;i<n;i++){
    cout<<v[i].c<<" ";
  }
}