#include<iostream>
using namespace std;
int n;
long long d[1504][1504],dp[1504][1504];//시작, 끝
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n;
      fill(&dp[0][0], &dp[0][0]+1504*1504,1e18);
      for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                  cin>>d[i][j];
            }
      }
      dp[1][1]=0;
      for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                  dp[i][j]=min(dp[i][j],d[i][i-1]+dp[i-1][j]);
                  dp[i][i-1]=min(dp[i][i-1], d[i][j]+dp[i-1][j]);
            }
      }
      long long ans=1e18;
      for(int i=1;i<=n;i++) ans=min(ans, dp[n][i]);
      cout<<ans;
}