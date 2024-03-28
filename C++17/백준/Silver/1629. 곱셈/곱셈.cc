#include <iostream>
using namespace std;
typedef long long int ll;
ll a,b,c;
ll f(ll x,ll y){
  if(y==1) return x%c;
  ll k=f(x,y/2);
  k=(k*k)%c;
  if(y%2==1) k=(k*x)%c;
  return k;
}
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>a>>b>>c;
  cout<<f(a,b);
}