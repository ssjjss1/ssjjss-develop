#include<iostream>
using namespace std;
string s1, s2;
int dp[1004][1004];
int main() {
  cin>>s1>>s2;
  for (int i = 1; i<=s1.size(); i++){
    for (int j = 1; j<=s2.size(); j++){
      int k=dp[i-1][j-1];
      if(s1[i-1]==s2[j-1]) k+=1;
      dp[i][j]=max(k,max(dp[i-1][j],dp[i][j-1]));
    }
  }
  cout<<dp[s1.size()][s2.size()];
}