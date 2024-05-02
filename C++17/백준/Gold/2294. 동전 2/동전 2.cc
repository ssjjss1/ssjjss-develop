#include<iostream>
using namespace std;
int n,m;
int a[100004],dp[100004];
int main(){
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  fill(dp,dp+m+1,1e9);
  dp[0]=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(j-a[i]>=0){
        dp[j]=min(dp[j],dp[j-a[i]]+1);
      }
    }
  }
  if(dp[m]==1e9) cout<<-1;
  else cout<<dp[m];
}