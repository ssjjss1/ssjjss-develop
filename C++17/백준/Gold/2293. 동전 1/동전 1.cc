#include<iostream>
using namespace std;
int n,m;
int a[101];
int dp[100001];
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  dp[0]=1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(j-a[i]>=0) dp[j]+=dp[j-a[i]]; 
    }
  }
  cout<<dp[m];
}