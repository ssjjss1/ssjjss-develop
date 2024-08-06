#include<iostream>
using namespace std;
int n;
int a[1004];
int dp[1004];
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i],dp[i]=a[i];
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i-j<=0) break;
      dp[i]=min(dp[i],dp[i-j]+a[j]);
    }
  }
  cout<<dp[n];
}