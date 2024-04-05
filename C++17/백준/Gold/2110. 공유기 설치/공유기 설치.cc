#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
ll n,m;
ll a[200004];
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  ll r=1,l=a[n-1]-a[0],ans=0;
  while(r<=l){
    ll middle=(r+l)/2;
    ll cnt=1;
    ll k=a[0];
    for(int i=0;i<n;i++){
      if(a[i]-k>=middle){
        cnt+=1;
        k=a[i];
      }
    }
    if(cnt>=m){
      ans=max(middle,ans);
      r=middle+1;
    }
    else l=middle-1;
  }
  cout<<ans;
}