#include<iostream>
using namespace std;
int n;
const int mod=10007;
int dp[1004][14];
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  for(int i=0;i<10;i++) dp[1][i]=1;
  for(int i=2;i<=n;i++){
    for(int j=0;j<10;j++){
      for(int k=0;k<=j;k++){
        dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
      }
    }
  }
  int ans=0;
  for(int i=0;i<10;i++) ans=(ans+dp[n][i])%mod;
  cout<<ans;
}