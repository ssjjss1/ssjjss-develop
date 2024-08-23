#include<iostream>
using namespace std;
int n,m;
long long dp[24][24];
long long f(long long x, long long y){
  return y?f(y,x%y):x;
}
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m;
  dp[1][1]=1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      dp[i][j]=max(dp[i][j], dp[i-1][j-1]+dp[i-1][j]*(i-1));
    }
  }
  for(int i=1;i<=n;i++) dp[n][i]+=dp[n][i-1];
  long long mod=f(dp[n][n],dp[n][m]);
  cout<<dp[n][m]/mod<<"/"<<dp[n][n]/mod;
}