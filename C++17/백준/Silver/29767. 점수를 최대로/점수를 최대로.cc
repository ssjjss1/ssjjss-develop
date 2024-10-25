#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long sum[300004];
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n>>k;
      for(int i=1,x;i<=n;i++) cin>>x,sum[i]+=(x+sum[i-1]);
      sort(sum+1,sum+n+1,greater<>());
      for(int i=1;i<=k;i++) ans+=sum[i];
      cout<<ans;
}