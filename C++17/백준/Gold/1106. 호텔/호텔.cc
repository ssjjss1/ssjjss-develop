#include<bits/stdc++.h>
#define INF 1e9+7
using namespace std;
int c,n;
vector<pair<int,int>> v;
int dp[2005];
int main(){
      ios::sync_with_stdio(0);cin.tie(0);
      cin>>c>>n;
      for(int i=1;i<=n;i++) {
            int x, y;
            cin>>x>>y;
            v.push_back({x,y});
      }
      fill(dp,dp+2004,INF);
      dp[0]=0;
      for(auto i:v){
            int cost=i.first, customer=i.second;
            for(int j=customer;j<=c+100;j++){
                  if(dp[j-customer]!=INF){
                        dp[j]=min(dp[j], dp[j-customer]+cost);
                  }
            }
      }
      int ans=INF;
      for(int i=c;i<=c+100;i++) ans=min(ans,dp[i]);
      cout<<ans;
}