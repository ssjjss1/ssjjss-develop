#include<iostream>
using namespace std;
long long int n,m,ans;
int a[11];
int main(){
  cin>>n>>m;
  for(int i=1;i<=n;i++) cin>>a[i];
  for(int i=n;i>=1;i--) ans+=(m/a[i]),m%=a[i];
  cout<<ans;
}