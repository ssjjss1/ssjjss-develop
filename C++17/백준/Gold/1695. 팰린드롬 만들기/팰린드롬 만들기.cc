#include<iostream>
using namespace std;
int n;
int d[5004];
int dp[5004][5004];
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++) cin>>d[i];
  for(int l=1;l<=n;l++){
    for(int i=1;i+l-1<=n;i++){
      int j=i+l-1;
      if(d[i]==d[j]) dp[i][j]=dp[i+1][j-1];
      else dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
    }
  }
  cout<<dp[1][n];
}