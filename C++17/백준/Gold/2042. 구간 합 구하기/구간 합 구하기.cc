#include<iostream>
#include<vector>
using namespace std;
typedef long long int ll;
int n,m,k;
ll x,y,z;
ll g(vector<ll> &v, ll b){
  ll ans=0;
  while(b){
    ans+=v[b];
    b-=(b&-b);
  }
  return ans;
}
void f(vector<ll> &v,ll b, ll c){
  while(b<v.size()){
    v[b]+=c;
    b+=(b&-b);
  }
}
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m>>k;
  vector<ll> a(n+1);
  vector<ll> v(n+1);
  m+=k;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    f(v,i,a[i]);
  }
  for(int i=0;i<m;i++){
    cin>>x;
    if(x==1){
      cin>>y>>z;
      ll p=z-a[y];
      a[y]=z;
      f(v,y,p);
    }
    else{
      cin>>y>>z;
      cout<<g(v,z)-g(v,y-1)<<"\n";
    }
  }
}