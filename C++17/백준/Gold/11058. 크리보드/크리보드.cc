#include<iostream>
using namespace std;
int n;
long long dp[104];
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  for(int i=0;i<=6;i++) dp[i]=i;
  for(int i=7;i<=n;i++){
    for(int j=3;j<i;j++){
      dp[i]=max(dp[i],dp[i-j]*(j-1));
    }
  }
  cout<<dp[n];
}