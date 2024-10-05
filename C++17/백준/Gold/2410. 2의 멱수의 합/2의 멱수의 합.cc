#include<iostream>
using namespace std;
const int mod=1e9;
int n;
long long dp[1000004];
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n;
      dp[0]=1;
      for(int i=1;i<=n;i++){
            if(i%2) dp[i]=dp[i-1];
            else dp[i]=dp[i-1]+dp[i/2];
            dp[i]%=mod;
      }
      cout<<dp[n];
}