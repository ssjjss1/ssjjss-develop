#include<iostream>
using namespace std;
string s1, s2;
int dp[1001][1001];
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>s1>>s2;
  for (int i = 1; i<=s1.size(); i++){
    for (int j = 1; j<=s2.size(); j++){
      int k=dp[i-1][j-1];
      if(s1[i-1]==s2[j-1]) k+=1;
      dp[i][j]=max(k,max(dp[i][j-1],dp[i-1][j]));
    }
  }
  cout<<dp[s1.size()][s2.size()]<<"\n";
  int x=s1.size(),y=s2.size();
  string s="";
  while(dp[x][y]){
    if(dp[x][y]==dp[x-1][y]) x-=1;
    else if(dp[x][y]==dp[x][y-1]) y-=1;
    else s+=s1[x-1],x-=1,y-=1;
  }
  for(int i=s.size()-1;i>=0;i--){
    cout<<s[i];
  }
}