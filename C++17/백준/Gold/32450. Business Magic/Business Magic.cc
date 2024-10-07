#include<iostream>
using namespace std;
const int inf=100004;
long long n,d[3*inf+4];
long long dp[3*inf+4], dpl[3*inf+4],dpr[3*inf+4];
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n;
      for(int i=1;i<=n;i++) cin>>d[i];
      for(int i=1;i<=n;i++){
            dpl[i]=dpl[i-1]+abs(d[i]);
            dp[i]=dp[i-1]+d[i];
      }
      for(int i=n;i>=1;i--) dpr[i]=dpr[i+1]+abs(d[i]);
      long long mn=0,ans=dpl[n];
      for(int i=1;i<=n;i++){
          ans=max(ans,2*dp[i]-mn+dpr[i+1]);
          mn=min(mn, -dpl[i]+2*dp[i]);
      }
      cout<<ans;
}