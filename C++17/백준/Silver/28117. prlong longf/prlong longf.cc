#include<bits/stdc++.h>
using namespace std;
int n;
long long d[84], dp[84];
string s;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      cin>>n>>s;
      int idx=0;
      dp[0]=1;
      dp[1]=1;
      for(int i=2;i<=20;i++){
            dp[i]=dp[i-1]+dp[i-2];
      }
      
      for(int i=0;i<n-3;i++){
            if(s.substr(i,4)=="long") d[idx]+=1, i+=3;
            else idx+=1;
      }
      
      long long ans=1;
      
      for(int i=0;i<=idx;i++){
            ans*=dp[d[i]];
      }
      
      cout<<ans;
}