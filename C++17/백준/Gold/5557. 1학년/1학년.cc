// }
#include<iostream>
using namespace std;
long long int dp[101][21];
int a[101];
int n;
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  dp[1][a[1]]=1;
  for(int i=2;i<=n;i++){
    for(int j=0;j<=20;j++){
      if(j-a[i]>=0) dp[i][j-a[i]]+=dp[i-1][j];
      if(j+a[i]<=20) dp[i][j+a[i]]+=dp[i-1][j];
    }
  }
  cout<<dp[n-1][a[n]];
}