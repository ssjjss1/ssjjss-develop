#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
vector<ll> v;
ll n,ans=-1,k;
ll a[1001],b[1001],c[1001];
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  fill(b,b+1001,1);
  fill(c,c+1001,-1);
  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
      if(a[j]<a[i]&&b[j]+1>b[i]){
        b[i]=b[j]+1;
        c[i]=j;
        if(b[i]>ans) ans=b[i],k=i;
      }
    }
  }
  if(ans==-1) cout<<1<<"\n";
  else cout<<ans<<"\n";
  int i=k;
  for(;c[i]!=-1;i=c[i]){
    v.push_back(a[i]);
  }
  v.push_back(a[i]);
  for(int j=v.size()-1;j>=0;j--){
    cout<<v[j]<<" ";
  }
}
