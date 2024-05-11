#include<bits/stdc++.h>
using namespace std;
struct P{float f;int a,b,c;};
bool compare(const P &x,const P &y){return x.f==y.f? x.c<y.c:x.f>y.f;}
vector<P> v;
int main(){
  int n;cin>>n;
  for(int i=1,x,y;i<=n;i++)cin>>x>>y,v.push_back({float(y)/float(x),x,y,i});
  sort(v.begin(),v.end(),compare);
  for(int i=0;i<n;i++)cout<<v[i].c<<" ";
}