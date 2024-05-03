#include<iostream>
using namespace std;
long long int dp[101][11];
long long int n,ans;
const int num=1000000000;
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  for(int i=1;i<=9;i++){
    dp[1][i]=1;
  }
  for(int i=2;i<=n;i++){
    for(int j=0;j<=9;j++){
      if(j==0) dp[i][j]=dp[i-1][j+1]%num;
      else if(j==9) dp[i][j]=dp[i-1][j-1]%num;
      else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%num;
    }
  }
  for(int i=0;i<=9;i++){
    ans+=dp[n][i];
  }
  cout<<ans%num;
}